// Link: https://leetcode.com/problems/n-th-tribonacci-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach:
// 1. If n is 0, return 0. If n is 1 or 2, return 1.
// 2. Initialize three variables a, b, c to store the last three tribonacci numbers
// 3. Iterate from 3 to n, and for each iteration, calculate the next tribonacci number as the sum of the last three numbers, and update a, b, c accordingly.
// 4. Return c, which will hold the nth tribonacci number after the loop.
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