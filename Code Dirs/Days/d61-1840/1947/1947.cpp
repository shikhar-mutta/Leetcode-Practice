// Link: https://leetcode.com/problems/maximum-compatibility-score-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m^2 * q + 2^m * m) where m is the number of students/mentors and q is the number of questions
// SC: O(m^2 + 2^m) where m is the number of students/mentors
// Approach: DP + Bitmasking
//  1. Calculate the compatibility score for each student-mentor pair and store it in a 2D array score.
//  2. Use a bitmask to represent the assigned mentors for each student. The bitmask will have m bits, where the j-th bit is set if the j-th mentor is assigned to a student.
//  3. Use dynamic programming to find the maximum compatibility score sum. The state dp[mask] represents the maximum compatibility score sum for the assigned mentors represented by the bitmask mask
// 4. Iterate through all possible bitmasks and for each bitmask, find the next student to assign and iterate through all mentors to find the maximum compatibility score sum.
class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students,
                            vector<vector<int>> &mentors)
    {
        int m = students.size(), q = students[0].size();
        vector<vector<int>> score(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < q; ++k)
                    score[i][j] += (students[i][k] == mentors[j][k]);

        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << m); ++mask)
        {
            if (dp[mask] < 0)
                continue;
            int i = __builtin_popcount(mask); // next student to assign
            if (i >= m)
                continue;
            for (int j = 0; j < m; ++j)
            {
                if (mask & (1 << j))
                    continue;
                int nmask = mask | (1 << j);
                dp[nmask] = max(dp[nmask], dp[mask] + score[i][j]);
            }
        }
        return dp[(1 << m) - 1];
    }
};
