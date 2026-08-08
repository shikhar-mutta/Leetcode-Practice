// Link: https://leetcode.com/problems/apply-discount-every-n-orders/description/

#include <bits/stdc++.h>
using namespace std;

class Cashier {
public:
    unordered_map<int,int> priceMap;
    int n, discount;
    int customerCount = 0;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), discount(discount) {
        for (int i = 0; i < (int)products.size(); i++) priceMap[products[i]] = prices[i];
    }

    double getBill(vector<int> product, vector<int> amount) {
        customerCount++;
        double total = 0;
        for (int i = 0; i < (int)product.size(); i++) total += priceMap[product[i]] * amount[i];
        if (customerCount % n == 0) total *= (100 - discount) / 100.0;
        return total;
    }
};
