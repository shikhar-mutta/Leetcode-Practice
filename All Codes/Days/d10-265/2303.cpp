// Link: https://leetcode.com/problems/calculate-amount-paid-in-taxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Huristic.
    // TC: O(n). SC: O(1).
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double ans = 0;
        int n = brackets.size();
        for (int i = 0; i < n; i++)
        { // Lower bound of the current tax bracket.
            int lower = (i == 0) ? 0 : brackets[i - 1][0];
            int taxable = min(brackets[i][0], income) - lower; // Taxable income in this bracket.
            if (taxable <= 0)// If taxable income is zero or negative,
                break;                               // No more taxable income left.
            ans += taxable * brackets[i][1] / 100.0; // Add tax for this bracket.
        }
        return ans;
    }
};
