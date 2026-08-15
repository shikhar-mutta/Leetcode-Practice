// Link: https://leetcode.com/problems/maximum-points-tourist-can-earn/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int> dp(n, 0); // dp[city] = best score for days processed so far, ending in city
        for (int day = 0; day < k; day++) {
            vector<int> ndp(n, 0);
            for (int city = 0; city < n; city++) {
                int best = dp[city] + stayScore[day][city];
                for (int from = 0; from < n; from++) {
                    if (from == city) continue;
                    best = max(best, dp[from] + travelScore[from][city]);
                }
                ndp[city] = best;
            }
            dp = ndp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
