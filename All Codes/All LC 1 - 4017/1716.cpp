// Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) where n is the number of days.
    // SC: O(1) for storing the total amount of money.
    // Approach:
    //  1. Calculate the number of complete weeks and remaining days.
    //  2. Calculate the total amount of money for complete weeks using the formula for the sum of an arithmetic series.
    //  3. Calculate the total amount of money for remaining days by adding the amount for each day.
    //  4. Return the total amount of money.
    int totalMoney(int n)
    {
        int weeks = n / 7, days = n % 7;
        int total = weeks * 28 + 7 * (weeks * (weeks - 1) / 2);
        for (int d = 0; d < days; ++d)
            total += weeks + 1 + d;
        return total;
    }
};
