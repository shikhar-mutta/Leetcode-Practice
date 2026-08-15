// Link: https://leetcode.com/problems/number-of-digit-one/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(logN) SC: O(1)
    //   Approach:
    //   1. We can use a mathematical approach to solve this problem. We can iterate through the digits of the number and for each digit, we can calculate the number of times it appears in the range from 1 to n. We can do this by calculating the number of complete cycles of 10 for each digit and then adding the number of times the digit appears in the incomplete cycle. We can continue this process for each digit until we reach the most significant digit. We can then return the total count of the digit 1 in the range from 1 to n.
    //  2. We can use a loop to iterate through the digits of the number and for each digit, we can calculate the number of times it appears in the range from 1 to n. We can do this by calculating the number of complete cycles of 10 for each digit and then adding the number of times the digit appears in the incomplete cycle. We can continue this process for each digit until we reach the most significant digit. We can then return the total count of the digit 1 in the range from 1 to n.
    int countDigitOne(int n)
    {
        long long count = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            count += (n / divider) * i + min(max((long long)(n % divider) - i + 1, 0LL), i);
        }
        return (int)count;
    }
};
