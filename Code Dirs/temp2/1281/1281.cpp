// Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int prod = 1, sum = 0;
        while (n)
        {
            int d = n % 10;
            prod *= d;
            sum += d;
            n /= 10;
        }
        return prod - sum;
    }
};