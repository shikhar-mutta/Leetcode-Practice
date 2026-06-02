// Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size(), j, newPr;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            j = i + 1;
            newPr = prices[i];
            // Find the first price that is less than or equal to the current price
            while (j < n && prices[j] > prices[i])
                j++;
            // If such a price is found, apply the discount
            if (j < n)
                newPr = prices[i] - prices[j];
            ans.push_back(newPr);
        }
        return ans;
    }
};
