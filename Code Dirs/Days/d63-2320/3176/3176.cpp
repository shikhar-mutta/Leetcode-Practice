// Link: https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k), SC: O(n*k)
// Approach: dp[i][j] = length of the longest good subsequence starting at
// index i using up to j allowed "mismatches" (adjacent pairs with different
// values) so far. At each i, either extend via the next equal-value index p
// (no mismatch spent) or via the best subsequence starting anywhere with
// j-1 mismatches remaining (max_k[j-1], a mismatch spent). max_k tracks the
// running best dp value for each mismatch budget across all i seen so far.
int dp[5000][51];
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 0, max_k[51] = {};
        map<int, int> next_ind;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto it = next_ind.find(nums[i]);
            int p = it != end(next_ind) ? it->second : i;
            for (int j = k; j >= 0; --j) {
                dp[i][j] = max(1 + (i != p ? dp[p][j] : 0),
                               1 + (j ? max_k[j - 1] : 0));
                max_k[j] = max(max_k[j], dp[i][j]);
            }
            next_ind[nums[i]] = i;
            res = max(res, dp[i][k]);
        }
        return res;
    }
};
