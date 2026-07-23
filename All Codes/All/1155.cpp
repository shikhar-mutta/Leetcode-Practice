// Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k * target) where n is the number of dice, k is the number of faces on each die, and target is the desired sum
// SC: O(n * target) for the memoization table
//   Approach:
//    1. Use a recursive function with memoization to calculate the number of ways to roll n dice to achieve the target sum.
//    2. The base case is when there are no dice left (n == 0) and the target is also 0, which means one valid way has been found. If there are no dice left but the target is not 0, return 0 as there are no valid ways.
//    3. If the target is less than the number of dice (n) or greater than the maximum possible sum (k * n), return 0 as it's impossible to achieve the target.
//    4. For each die, iterate through all possible face values (from 1 to k) and recursively call the function for the remaining dice and the adjusted target (target - face value). Accumulate the number of ways found in each recursive call.
//    5. Store the result in the memoization table to avoid redundant calculations for the same state (n, target).
//    6. Return the total number of ways modulo 10^9 + 7 to handle large numbers.
class Solution
{
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int find(int n, int k, int target)
    {
        1155_driver.cpp 1155_expected.txt 1155_input.txt 1155.cpp if (n == 0) return (target == 0);
        if (target < n || target > k * n)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        long long ways = 0;
        for (int i = 1; i <= k; i++)
        {
            if (target >= i)
            {
                ways = (ways + find(n - 1, k, target - i)) % MOD;
            }
        }
        return dp[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        dp.assign(n + 1, vector<int>(target + 1, -1));
        return find(n, k, target);
    }
};