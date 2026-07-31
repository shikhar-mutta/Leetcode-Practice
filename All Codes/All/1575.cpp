// Link: https://leetcode.com/problems/count-all-possible-routes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * f) SC: O(n * f)
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][f] represents the number of ways to reach location i with f fuel. We can initialize dp[start][0] = 1 since we start at the start location with 0 fuel. Then, we can iterate through all possible fuel values and for each fuel value, we can iterate through all locations and for each location, we can iterate through all other locations to calculate the number of ways to reach that location with the remaining fuel. Finally, we return the sum of all dp[finish][f] for all f from 0 to fuel.
class Solution
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        static const int MOD = 1e9 + 7;

        int s = locations[start];
        int f = locations[finish];
        sort(begin(locations), end(locations));
        start = distance(cbegin(locations), lower_bound(cbegin(locations), cend(locations), s));
        finish = distance(cbegin(locations), lower_bound(cbegin(locations), cend(locations), f));

        vector<vector<int>> left(locations.size(), vector<int>(fuel + 1));  // left[i][f], last move is toward left to location i by f fuel
        vector<vector<int>> right(locations.size(), vector<int>(fuel + 1)); // right[i][f], last move is toward right to location i by f fuel
        for (int f = 1; f <= fuel; ++f)
        {
            for (int j = 0; j < locations.size() - 1; ++j)
            {
                int d = locations[j + 1] - locations[j];
                if (f > d)
                {
                    left[j][f] = (right[j + 1][f - d] + 2 * left[j + 1][f - d] % MOD) % MOD;
                }
                else if (f == d)
                {
                    left[j][f] = int(j + 1 == start);
                }
            }
            for (int j = 1; j < locations.size(); ++j)
            {
                int d = locations[j] - locations[j - 1];
                if (f > d)
                {
                    right[j][f] = (left[j - 1][f - d] + 2 * right[j - 1][f - d] % MOD) % MOD;
                }
                else if (f == d)
                {
                    right[j][f] = int(j - 1 == start);
                }
            }
        }
        int result = int(start == finish);
        for (int f = 1; f <= fuel; ++f)
        {
            result = ((result + left[finish][f]) % MOD + right[finish][f]) % MOD;
        }
        return result;
    }
};

// Time:  O(n^2 * f)
// Space: O(n * f)
class Solution2
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1));
        dp[start][0] = 1;
        for (int f = 1; f <= fuel; ++f)
        {
            for (int i = 0; i < locations.size(); ++i)
            {
                for (int j = 0; j < locations.size(); ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    int d = abs(locations[i] - locations[j]);
                    if (f - d < 0)
                    {
                        continue;
                    }
                    dp[i][f] = (static_cast<int64_t>(dp[i][f]) + dp[j][f - d]) % MOD;
                }
            }
        }
        return accumulate(cbegin(dp[finish]), cend(dp[finish]), 0LL,
                          [&](const int64_t a, const int b)
                          {
                              return (a + b) % MOD;
                          });
    }
};