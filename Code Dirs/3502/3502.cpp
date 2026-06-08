// Link: https://leetcode.com/problems/minimum-cost-to-reach-every-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    vector<int> minCosts(vector<int> &cost)
    {
        int n = cost.size();
        cost[0] = cost[0];
        for (int i = 1; i < n; i++)
            cost[i] = min(cost[i - 1], cost[i]);

        return cost;
    }
};
