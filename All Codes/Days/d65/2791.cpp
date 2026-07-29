// Link: https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*26), SC: O(N)
// Approach: mask[u] = XOR of character bitmasks from root to u. A path u-v's letters can form a
// palindrome iff mask[u]^mask[v] has at most one bit set (at most one odd-count letter). Since
// parent[i] < i is guaranteed, compute masks in index order, and count matches (same mask, or
// differing by exactly one bit) against a running frequency map as we go.
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> mask(n, 0);
        mask[0] = 1 << (s[0] - 'a');
        for (int i = 1; i < n; i++) mask[i] = mask[parent[i]] ^ (1 << (s[i] - 'a'));

        unordered_map<int,long long> freq;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int m = mask[i];
            ans += freq[m];
            for (int b = 0; b < 26; b++) {
                auto it = freq.find(m ^ (1 << b));
                if (it != freq.end()) ans += it->second;
            }
            freq[m]++;
        }
        return ans;
    }
};
