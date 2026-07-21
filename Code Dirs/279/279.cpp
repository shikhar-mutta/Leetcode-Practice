// Link: https://leetcode.com/problems/perfect-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)) for checking perfect square and O(sqrt(n)) for the loop, so overall O(sqrt(n))
// SC: O(1)
//  Approach:
//  1. Check if n is a perfect square, if yes return 1
//  2. Check if n can be expressed as 4^k*(8*m + 7), if yes return 4
//  3. Check if n can be expressed as the sum of two perfect squares, if yes return 2
//  4. If none of the above conditions are met, return 3

class Solution
{
public:
    bool isperfectsquare(int n)
    {
        int root = sqrt(n);
        return root * root == n;
    }

    int numSquares(int n)
    {
        if (isperfectsquare(n))
            return 1;

        while (n % 4 == 0)
        {
            n /= 4;
        }
        if (n % 8 == 7)
            return 4;

        for (int i = 1; i * i <= n; i++)
        {
            if (isperfectsquare(n - i * i))
                return 2;
        }

        return 3;
    }
};
