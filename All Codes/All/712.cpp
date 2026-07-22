// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(m*n) and SC: O(n)
//Approach:
//1. We use a dynamic programming approach to find the minimum ASCII delete sum for two strings
//2. We maintain a 2D dp array where dp[i][j] represents the minimum ASCII delete sum for the first i characters of s1 and the first j characters of s2
//3. If the characters at the current position are equal, we move diagonally in the dp array, otherwise we take the minimum of deleting from s1 or s2 and add the ASCII value of the deleted character
//4. We return the value at dp[m][n] as the final result, where m and n are the lengths of s1 and s2 respectively
class Solution
{
private:
    int findMinSum(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {

        if (i == 0 && j == 0)
            return 0;

        if (i == 0)
        {
            int sum = 0;
            while (j > 0)
            {
                sum += int(s2[j - 1]);
                j--;
            }
            return sum;
        }

        if (j == 0)
        {
            int sum = 0;
            while (i > 0)
            {
                sum += int(s1[i - 1]);
                i--;
            }
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
        {
            return dp[i][j] = findMinSum(i - 1, j - 1, s1, s2, dp);
        }

        int deleteFrom1 = int(s1[i - 1]) + findMinSum(i - 1, j, s1, s2, dp);
        int deleteFrom2 = int(s2[j - 1]) + findMinSum(i, j - 1, s1, s2, dp);

        return dp[i][j] = min(deleteFrom1, deleteFrom2);
    }

public:
    int minimumDeleteSum(string s1, string s2)
    {

        int m = s1.length();
        int n = s2.length();

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        prev[0] = 0;

        int sum = 0;

        for (int j = 1; j <= n; j++)
        {
            prev[j] = prev[j - 1] + int(s2[j - 1]);
        }

        for (int i = 1; i <= m; i++)
        {
            cur[0] = prev[0] + int(s1[i - 1]);
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    cur[j] = prev[j - 1];
                }

                else
                {
                    int deleteFrom1 = int(s1[i - 1]) + prev[j];
                    int deleteFrom2 = int(s2[j - 1]) + cur[j - 1];

                    cur[j] = min(deleteFrom1, deleteFrom2);
                }
            }
            prev = cur;
        }

        return prev[n];
    }
};