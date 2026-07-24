// Link: https://leetcode.com/problems/apply-discount-every-n-orders/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach:
//  1. We can use an unordered_map to store the prices of each product, where the key is the product ID and the value is the price.
//  2. We can also keep track of the number of orders processed so far using a counter variable.
//  3. In the getBill function, we can iterate through the product and amount vectors to calculate the total bill. If the counter variable is equal to n, we can apply the discount to the total bill and reset the counter variable to 0. Finally, we return the total bill.
class Cashier
{
public:
    unordered_map<int, int> mp;
    int dis;
    int nth = 0;
    int c = 0;
    Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
    {
        dis = discount;
        nth = n;
        for (int i = 0; i < products.size(); i++)
        {
            mp[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount)
    {
        double sum = 0;
        ++c;
        for (int i = 0; i < product.size(); i++)
        {
            sum += mp[product[i]] * amount[i];
        }

        if (c == nth)
        {
            sum = sum * ((100 - dis) / 100.0);
            c = 0;
        }
        return sum;
    }
};
