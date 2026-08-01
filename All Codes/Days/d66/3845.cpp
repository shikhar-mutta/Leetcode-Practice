// Link: https://leetcode.com/problems/maximum-subarray-xor-with-bounded-range/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log maxVal)  SC: O(n log maxVal)
// Approach: "bounded range" means max(subarray)-min(subarray) <= k.
// Maintain a sliding window [left,right] with monotonic deques tracking the
// window's max/min, shrinking left whenever the range exceeds k; every
// subarray [l,right] with l in [left,right] is automatically also within
// range k (it's a subset of the window). Maintain a counting binary trie of
// prefixXor[l] for l in the current window (inserting prefixXor[right] as
// right expands, removing prefixXor[left] as left advances), and for each
// right query the trie for the value maximizing XOR with
// prefixXor[right+1] — the classic max-XOR-subarray trie technique, now
// restricted to a sliding validity window.
class Solution {
    static const int BITS = 30;
    struct TrieNode { int child[2] = {-1,-1}; int cnt = 0; };
    vector<TrieNode> trie;

    void insert(int val) {
        int cur = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (val >> b) & 1;
            if (trie[cur].child[bit] == -1) {
                trie[cur].child[bit] = trie.size();
                trie.push_back(TrieNode());
            }
            cur = trie[cur].child[bit];
            trie[cur].cnt++;
        }
    }
    void remove(int val) {
        int cur = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (val >> b) & 1;
            cur = trie[cur].child[bit];
            trie[cur].cnt--;
        }
    }
    int queryMax(int val) {
        int cur = 0, res = 0;
        for (int b = BITS; b >= 0; b--) {
            int bit = (val >> b) & 1;
            int want = bit ^ 1;
            if (trie[cur].child[want] != -1 && trie[trie[cur].child[want]].cnt > 0) {
                res |= (1 << b);
                cur = trie[cur].child[want];
            } else {
                cur = trie[cur].child[bit];
            }
        }
        return res;
    }
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixXor(n + 1, 0);
        for (int i = 0; i < n; i++) prefixXor[i+1] = prefixXor[i] ^ nums[i];

        trie.push_back(TrieNode());
        deque<int> maxDq, minDq;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            insert(prefixXor[right]);
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[right]) maxDq.pop_back();
            maxDq.push_back(right);
            while (!minDq.empty() && nums[minDq.back()] >= nums[right]) minDq.pop_back();
            minDq.push_back(right);

            while (nums[maxDq.front()] - nums[minDq.front()] > k) {
                remove(prefixXor[left]);
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();
                left++;
            }
            ans = max(ans, queryMax(prefixXor[right+1]));
        }
        return ans;
    }
};
