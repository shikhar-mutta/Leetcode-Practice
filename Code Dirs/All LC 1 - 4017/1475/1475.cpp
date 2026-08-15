// Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res = prices;
        for (int i = 0; i < (int)prices.size(); i++) {
            for (int j = i + 1; j < (int)prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    res[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return res;
    }
};
