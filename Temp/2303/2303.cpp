// Link: https://leetcode.com/problems/calculate-amount-paid-in-taxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int prev = 0;
        for (auto& b : brackets) {
            int upper = b[0], percent = b[1];
            if (income <= prev) break;
            int amount = min(income, upper) - prev;
            tax += (double)amount * percent / 100.0;
            prev = upper;
        }
        return tax;
    }
};
