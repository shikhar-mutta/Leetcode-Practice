// Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lisLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        return dp;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = lisLen(nums);
        vector<int> rev(nums.rbegin(), nums.rend());
        vector<int> rightRev = lisLen(rev);
        vector<int> right(n);
        for (int i = 0; i < n; i++) right[i] = rightRev[n - 1 - i];

        int best = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] >= 2 && right[i] >= 2) {
                best = max(best, left[i] + right[i] - 1);
            }
        }
        return n - best;
    }
};
