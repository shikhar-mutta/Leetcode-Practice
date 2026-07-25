// Link: https://leetcode.com/problems/maximum-product-of-two-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    // Approach:
    //  1. We can find the two largest digits in the number by iterating through each digit and keeping track of the two largest digits found so far.
    //  2. We can then return the product of these two digits.
    int maxProduct(int n)
    {
        int first = 0, second = 0;
        while (n)
        {
            int d = n % 10;
            if (d >= first)
            {
                second = first;
                first = d;
            }
            else if (d > second)
                second = d;
            n /= 10;
        }
        return first * second;
    }
};