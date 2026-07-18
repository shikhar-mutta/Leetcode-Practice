// Link: https://leetcode.com/problems/climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: Fibonacci sequence, ways(n) = ways(n-1) + ways(n-2)
    int climbStairs(int n)
    {
        // Fibonacci: ways(n) = ways(n-1) + ways(n-2)
        int a = 1, b = 1; // ways(0), ways(1)
        for (int i = 2; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
