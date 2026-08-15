// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k), SC: O(k)
// Approach: A valid subsequence needs every adjacent pair's sum mod k to
// equal a fixed target `rem`. For each candidate rem, dp[m] = length of the
// longest such subsequence ending in an element with remainder m; extending
// with a new element of remainder `num` requires the pairing remainder
// `rem-num` (mod k) as the previous element's remainder.
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int dp[1000], res = 0;
        for (int rem = 0; rem < k; ++rem) {
            for (int i = 0; i < k; ++i)
                dp[i] = 0;
            for (int x : nums) {
                int num = x % k, idx = rem - num;
                if (idx < 0)
                    idx += k;
                int curr = dp[idx] + 1;
                dp[num] = curr;
                if (curr > res)
                    res = curr;
            }
        }
        return res;
    }
};
