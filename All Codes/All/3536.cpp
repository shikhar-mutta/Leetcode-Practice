// Link: https://leetcode.com/problems/maximum-product-of-two-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) . SC: O(1) .
    int maxProduct(int n)
    {
        vector<int> digits(2, INT_MIN);
        while (n)
        {
            int d = n % 10;
            n /= 10;
            if (d > digits[0])
            {
                digits[1] = digits[0];
                digits[0] = d;
            }
            else if (d > digits[1])
                digits[1] = d;
        }
        return (digits[0]) * (digits[1]);
    }
};
