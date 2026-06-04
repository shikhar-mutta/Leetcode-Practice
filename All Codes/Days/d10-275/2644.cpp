// Link: https://leetcode.com/problems/find-the-maximum-divisibility-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(1)
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int maxScore = 0, bestDivisor = INT_MAX, n = nums.size(), m = divisors.size();
        for (int i = 0; i < m; i++)
        {
            int score = 0;
            for (int j = 0; j < n; j++)
                if (nums[j] % divisors[i] == 0)
                    score++;

            if (score > maxScore || (score == maxScore && divisors[i] < bestDivisor))
            {
                maxScore = score;
                bestDivisor = divisors[i];
            }
        }
        return bestDivisor;
    }
};
