// Link: https://leetcode.com/problems/maximum-earnings-from-taxi/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of rides and m is the maximum end point of the rides.
    // SC: O(n + m) where n is the number of rides and m is the maximum end point of the rides.
    // Approach:
    // 1. Create a vector of vectors to store the rides starting at each point.
    // 2. Create a dp vector to store the maximum earnings starting from each point.
    // 3. Iterate from the end of the dp vector to the beginning, updating the maximum earnings at each point based on the rides starting at that point and the maximum earnings from the next point.
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        // ridesAt[s] = {end, profit} for every ride starting at s
        vector<vector<pair<int, int>>> ridesAt(n + 1);
        for (auto &r : rides)
            ridesAt[r[0]].push_back({r[1], r[1] - r[0] + r[2]});

        // dp[i] = max earnings starting from point i
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 1; i--)
        {
            dp[i] = dp[i + 1]; // skip point i
            for (auto &[end, profit] : ridesAt[i])
                dp[i] = max(dp[i], profit + dp[end]);
        }
        return dp[1];
    }
};
