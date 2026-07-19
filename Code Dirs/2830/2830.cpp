// Link: https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of houses and m is the number of offers.
    // SC: O(n + m) where n is the number of houses and m is the number of offers.
    // Approach:
    //  1. Create a vector of vectors to store the offers that end at each house.
    //  2. Iterate through the offers and populate the vector of vectors with the start and gold of each offer.
    //  3. Create a dp vector to store the maximum amount of gold that can be obtained by selling the first i houses.
    //  4. Iterate through the houses and for each house, update the dp vector with the maximum amount of gold that can be obtained by selling the first i houses.
    //  5. For each offer that ends at the current house, update the dp vector with the maximum amount of gold that can be obtained by selling the first i houses and taking the offer.
    //  6. Return the maximum amount of gold that can be obtained by selling all the houses.
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        // dp[i] := the maximum amount of gold of selling the first i houses
        vector<int> dp(n + 1);
        vector<vector<pair<int, int>>> endToStartAndGolds(n);

        for (const vector<int> &offer : offers)
        {
            const int start = offer[0];
            const int end = offer[1];
            const int gold = offer[2];
            endToStartAndGolds[end].emplace_back(start, gold);
        }

        for (int end = 1; end <= n; ++end)
        {
            // Get at least the same gold as selling the first `end - 1` houses.
            dp[end] = dp[end - 1];
            for (const auto &[start, gold] : endToStartAndGolds[end - 1])
                dp[end] = max(dp[end], dp[start] + gold);
        }

        return dp[n];
    }
};
