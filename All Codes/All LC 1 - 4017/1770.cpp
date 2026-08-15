// Link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore_(vector<int> &nums, vector<int> &multipliers)
    {
        vector<vector<int>> memo(multipliers.size(),
                                 vector<int>(multipliers.size(), -1));
        return go(0, nums.size() - 1, 0, nums, multipliers, memo);
    }

    int go(int l, int r, int i, vector<int> &nums, vector<int> &muls,
           vector<vector<int>> &memo)
    {
        if (i == muls.size())
            return 0; // Picked enough m elements
        if (memo[l][i] != -1)
            return memo[l][i];
        int pickLeft = go(l + 1, r, i + 1, nums, muls, memo) +
                       nums[l] * muls[i]; // Pick the left side
        int pickRight = go(l, r - 1, i + 1, nums, muls, memo) +
                        nums[r] * muls[i]; // Pick the right side
        return memo[l][i] = max(pickLeft, pickRight);
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        const int numberCount = nums.size();
        const int operationCount = multipliers.size();

        vector<vector<int>> dp(operationCount + 1,
                               vector<int>(operationCount + 1, 0));

        for (int operation = operationCount - 1; operation >= 0; --operation)
        {

            int multiplier = multipliers[operation];

            for (int leftTaken = 0; leftTaken <= operation; ++leftTaken)
            {

                int rightTaken = operation - leftTaken;
                int rightIndex = numberCount - 1 - rightTaken;
                int pickLeft = multiplier * nums[leftTaken] +
                               dp[operation + 1][leftTaken + 1];

                int pickRight = multiplier * nums[rightIndex] +
                                dp[operation + 1][leftTaken];

                dp[operation][leftTaken] = max(pickLeft, pickRight);
            }
        }

        return dp[0][0];
    }
};