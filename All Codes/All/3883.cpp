// Link: https://leetcode.com/problems/count-non-decreasing-arrays-with-given-digit-sums/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 5000)  SC: O(n * 400)
//   Approach: We can use dynamic programming to count the number of non-decreasing arrays that satisfy the given digit sums. We first precompute the digit sums for all numbers from 0 to 5000 and store them in a bucket array. We then initialize a 2D dp array where dp[i][j] represents the number of non-decreasing arrays of length i that end with a number whose digit sum is j. We iterate through the digitSum array and for each digit sum, we update the dp array by considering all possible previous digit sums that are less than or equal to the current digit sum. Finally, we return the value in dp[n-1][bkt[digitSum[n-1]].size()] which represents the total number of non-decreasing arrays of length n that satisfy the given digit sums.
class Solution
{
public:
    int countArrays(vector<int> &digitSum)
    {
        int n(digitSum.size());
        static vector<int> bkt[51];
        for (static int i(0); i < 5001; ++i)
        {
            int s(0);
            for (int x(i); x; x /= 10)
                s += x % 10;
            bkt[s].push_back(i);
        }

        int dp[n][400], mod(1e9 + 7);
        memset(dp, 0, sizeof(dp));
        for (int i(0); i < 400; ++i)
            dp[0][i] = i;

        for (int i(1); i < n; ++i)
        {
            int c = digitSum[i - 1];
            int d = digitSum[i];
            for (int j(0), k(0); j < bkt[d].size(); ++j)
            {
                while (k < bkt[c].size() && bkt[c][k] <= bkt[d][j])
                    ++k;
                dp[i][j + 1] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }

        return dp[n - 1][bkt[digitSum[n - 1]].size()];
    }
};
