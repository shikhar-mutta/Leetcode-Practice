// Link: https://leetcode.com/problems/best-team-with-no-conflicts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2)
    // SC: O(n)
    //  Approach:
    //   1. Create a vector of pairs to store the age and score of each player.
    //   2. Sort the players based on age and score.
    //   3. Use dynamic programming to find the best team score.
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<pair<int, int>> players(n); // (age, score)
        for (int i = 0; i < n; i++)
            players[i] = {ages[i], scores[i]};
        sort(players.begin(), players.end());

        vector<int> dp(n);
        int best = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = players[i].second;
            for (int j = 0; j < i; j++)
                if (players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            best = max(best, dp[i]);
        }
        return best;
    }
};
