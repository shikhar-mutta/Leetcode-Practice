// Link: https://leetcode.com/problems/maximum-strong-pair-xor-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N + N*20), SC: O(N*20)
// Approach: sort ascending. For y<=x, |x-y|<=min(x,y) simplifies to x<=2y. Two-pointer: insert
// nums[right] into a binary trie (with per-node reference counts so entries can be removed),
// then evict from the left while nums[right] > 2*nums[left] so the trie always holds exactly the
// valid partner window [left,right]; query it for the max XOR with nums[right].
class Solution {
public:
    static const int BITS = 20;
    struct Node { int child[2] = {-1,-1}; int count = 0; };
    vector<Node> trie;

    void insert(int x, int delta) {
        int cur = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (trie[cur].child[bit] == -1) {
                trie[cur].child[bit] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].child[bit];
            trie[cur].count += delta;
        }
    }
    int query(int x) {
        int cur = 0, res = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (trie[cur].child[want] != -1 && trie[trie[cur].child[want]].count > 0) {
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
        trie.assign(1, Node());
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            insert(nums[right], 1);
            while (nums[right] > 2 * nums[left]) { insert(nums[left], -1); left++; }
            ans = max(ans, query(nums[right]));
        }
        return ans;
    }
};
