// Link: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int maxReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= maxReach + 1)
            {
                maxReach += coins[i];
            }
            else
                break;
        }
        return maxReach + 1;
    }
};