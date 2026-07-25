// Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: DP from right to left. dp[i] = best score achievable starting
// from question i onward. At each i, either skip it (dp[i+1]) or solve it
// (its points plus whatever's achievable after skipping the next brainpower
// questions, dp[i + questions[i][1] + 1]); take the max of the two options.
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            long long take = questions[i][0];
            int next = i + questions[i][1] + 1;
            if (next < n)
                take += dp[next];

            long long skip = dp[i + 1];
            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};
