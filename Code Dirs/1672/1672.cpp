// Link: https://leetcode.com/problems/richest-customer-wealth/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int mx = 0;
        for (const auto &a : accounts)
        {
            int sum = 0;
            for (const auto &b : a)
                sum += b;
            if (sum > mx)
                mx = sum;
        }
        return mx;
    };
};
