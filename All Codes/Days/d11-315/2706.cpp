// Link: https://leetcode.com/problems/buy-two-chocolates/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int price : prices)
        {
            if (price < min1)
            {
                min2 = min1;
                min1 = price;
            }
            else if (price < min2)
            {
                min2 = price;
            }
        }
        return (min1 + min2 <= money) ? (money - min1 - min2) : money;
    }
};
