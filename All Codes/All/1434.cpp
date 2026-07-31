// Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(40 * 2^n * n)  SC: O(2^n)
// Approach: dp[mask] = number of ways to assign hats to the people represented by the mask. For each hat, we can either assign it to a person who doesn't have a hat yet (represented by the mask) or not assign it at all. We iterate through all hats and update the dp array accordingly.
class Solution
{
public:
    int numberWays(vector<vector<int>> &hats)
    {
        int MOD = 1e9 + 7, n = hats.size();

        vector<vector<int>> persons(40);
        vector<int> masks(1 << n);
        masks[0] = 1;

        for (int i = 0; i < n; i++)
            for (int &h : hats[i])
                persons[h - 1].push_back(i);

        for (int i = 0; i < 40; i++)
            for (int j = (1 << n) - 1; j >= 0; j--)
                for (int &p : persons[i])
                    if ((j & (1 << p)) == 0)
                    {
                        masks[j | (1 << p)] += masks[j];
                        masks[j | (1 << p)] %= MOD;
                    }

        return masks[(1 << n) - 1];
    }
};