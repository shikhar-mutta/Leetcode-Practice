// Link: https://leetcode.com/problems/n-th-tribonacci-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n < 3)
            return 1; // T1 = T2 = 1

        int a = 0, b = 1, c = 1; // T0, T1, T2
        for (int i = 3; i <= n; i++)
        {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};