// Link: https://leetcode.com/problems/minimum-total-price-after-applying-discounts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        long long totalPrice = 0;
        for (int p : prices) totalPrice += p;

        int k = min(prices.size(), discounts.size());
        long long discountValueTimes100 = 0;
        for (int i = 0; i < k; i++) {
            discountValueTimes100 += (long long)prices[i] * discounts[i];
        }

        double ans = (double)totalPrice - (double)discountValueTimes100 / 100.0;
        return ans;
    }
};
