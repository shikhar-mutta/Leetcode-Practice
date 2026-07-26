// Link: https://leetcode.com/problems/special-permutations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n^2)
// SC: O(2^n * n) for the memo table
// Approach: bitmask DP over (visited set, last placed index). At each state,
// try appending every unvisited nums[i] whose value divides or is divided by
// the previous element (or is first in the permutation), summing valid
// completions mod 1e9+7. dp[visited][prev+1] memoizes by shifting prev by 1
// to represent the "no previous element" state as index 0.
class Solution {
public:
    int dp[1 << 14][15];
    int mod = 1e9 + 7;
    int solution(vector<int>& nums, int visited, int prev) {
        int n = nums.size();
        if (visited == ((1 << n) - 1)) {
            return 1;
        }

        if (dp[visited][prev + 1] != -1) {
            return dp[visited][prev + 1];
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {

            int bit = (visited >> i) & 1;

            if (bit == 0 && (prev == -1 || nums[i] % nums[prev] == 0 ||
                             nums[prev] % nums[i] == 0)) {
                int newVis = visited | (1 << i);
                total = (total + solution(nums, newVis, i)) % mod;
            }
        }

        return dp[visited][prev + 1] = total;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solution(nums, 0, -1);
    }
};
