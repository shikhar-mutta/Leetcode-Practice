// Link: https://leetcode.com/problems/count-of-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the length of num2 and m is the maximum sum, SC: O(n * m) where n is the length of num2 and m is the maximum sum
//  Approach: We can use a digit dynamic programming approach to count the number of integers between num1 and num2 (inclusive) whose sum of digits is between min_sum and max_sum. We will define a recursive function helper that takes the current index, the current sum of digits, a boolean flag isLimit to indicate whether we are still under the limit of num2, and the minimum and maximum sum constraints. The base case is when we reach the end of the number, where we check if the current sum is within the specified range. We will also use memoization to store intermediate results in a dp array to avoid redundant calculations. Finally, we will call the helper function for both num2 and num1, and adjust the result based on whether num1 itself satisfies the sum constraints.
class Solution
{
    const int MOD = 1e9 + 7;
    int dp[23][405];

    int helper(const string &num, int idx, int sum, bool isLimit, int min_sum,
               int max_sum)
    {
        if (sum > max_sum)
            return 0;

        if (idx == num.size())
            return sum >= min_sum ? 1 : 0;

        int rem = num.size() - idx;

        if (!isLimit && dp[rem][sum] != -1)
            return dp[rem][sum];

        int cnt = 0;
        int upper_bound = isLimit ? (num[idx] - '0') : 9;

        for (int i = 0; i <= upper_bound; i++)
        {
            bool nextLimit = isLimit && (i == upper_bound);
            cnt = (cnt +
                   helper(num, idx + 1, sum + i, nextLimit, min_sum, max_sum)) %
                  MOD;
        }

        if (!isLimit)
            dp[rem][sum] = cnt;

        return cnt;
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {

        memset(dp, -1, sizeof(dp));

        int A = helper(num2, 0, 0, true, min_sum, max_sum);
        int B = helper(num1, 0, 0, true, min_sum, max_sum);

        int num1Sum = 0;
        for (char c : num1)
        {
            num1Sum += (c - '0');
        }
        int one = (min_sum <= num1Sum && num1Sum <= max_sum) ? 1 : 0;

        return (A - B + one + MOD) % MOD;
    }
};