// Link: https://leetcode.com/problems/ugly-number-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) - where n is the input number
    // SC: O(n) - where n is the input number
    // Approach:
    //  1. Create a vector to store the ugly numbers and initialize the first ugly number
    //  2. Use three pointers to keep track of the next multiple of 2, 3, and 5
    //  3. For each iteration, find the minimum of the next multiples of 2, 3, and 5 and add it to the ugly numbers
    //  4. Increment the pointer(s) for the multiple(s) that were used to generate the next ugly number
    //  5. Repeat until we have generated n ugly numbers and return the nth ugly number
    //  Note: An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
    int nthUglyNumber(int n)
    {
        vector<int> ugly(n);

        int i2 = 0, i3 = 0, i5 = 0;
        ugly[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int a = ugly[i2] * 2;
            int b = ugly[i3] * 3;
            int c = ugly[i5] * 5;

            int mini = min(a, min(b, c));

            ugly[i] = mini;

            if (mini == a)
                i2++;
            if (mini == b)
                i3++;
            if (mini == c)
                i5++;
        }

        return ugly[n - 1];
    }
};
