// Link: https://leetcode.com/problems/maximum-strong-pair-xor-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int BITS = 20;
    struct TrieNode {
        int child[2] = {-1, -1};
        int cnt = 0;
    };
    vector<TrieNode> trie;

    void insertVal(int x) {
        int cur = 0;
        for (int b = BITS - 1; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (trie[cur].child[bit] == -1) {
                trie[cur].child[bit] = trie.size();
                trie.push_back(TrieNode());
            }
            cur = trie[cur].child[bit];
            trie[cur].cnt++;
        }
    }

    void removeVal(int x) {
        int cur = 0;
        for (int b = BITS - 1; b >= 0; b--) {
            int bit = (x >> b) & 1;
            cur = trie[cur].child[bit];
            trie[cur].cnt--;
        }
    }

    int queryMax(int x) {
        int cur = 0, res = 0;
        for (int b = BITS - 1; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int want = 1 - bit;
            if (trie[cur].child[want] != -1 && trie[trie[cur].child[want]].cnt > 0) {
                res |= (1 << b);
                cur = trie[cur].child[want];
            } else {
                cur = trie[cur].child[bit];
            }
        }
        return res;
    }

    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        trie.clear();
        trie.push_back(TrieNode());
        int i = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            insertVal(nums[j]);
            while ((long long)nums[i] * 2 < nums[j]) {
                removeVal(nums[i]);
                i++;
            }
            ans = max(ans, queryMax(nums[j]));
        }
        return ans;
    }
};
