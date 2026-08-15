// Link: https://leetcode.com/problems/new-21-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //  1. Use dynamic programming to calculate the probability of reaching each score from 0 to n.
    //  2. Initialize dp[0] = 1.0, as the probability of starting at score 0 is 1.
    //  3. Use a sliding window to maintain the sum of probabilities for the last maxPts scores.
    //  4. For each score i from 1 to n, calculate dp[i] as the average of the probabilities of the last maxPts scores.
    //  5. If i is less than k, add dp[i] to the window sum. If i is greater than or equal to k, add dp[i] to the final answer.
    //  6. If i - maxPts is greater than or equal to 0, subtract dp[i - maxPts] from the window sum to maintain the sliding window.
    //  7. Return the final answer, which is the sum of probabilities for scores from k to n.
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || n >= k + maxPts - 1)
            return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0;
        double ans = 0.0;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = windowSum / maxPts;

            if (i < k)
                windowSum += dp[i];
            else
                ans += dp[i];

            if (i - maxPts >= 0)
                windowSum -= dp[i - maxPts];
        }

        return ans;
    }
};