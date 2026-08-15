// Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int totalCost = 0, n = cost.size();
        // Sort the cost in descending order to maximize the discount
        sort(cost.begin(), cost.end(), greater<int>());
        // Buy the candies in groups of three, skipping the cheapest one in each group
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 3 == 0)
                continue;
            totalCost += cost[i];
        }
        return totalCost;
    }
};
