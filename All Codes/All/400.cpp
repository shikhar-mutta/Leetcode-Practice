// Link: https://leetcode.com/problems/nth-digit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(n)) where n is the input integer. The while loop runs log(n) times as we are dividing n by 10 in each iteration.
    // SC: O(1) as we are using a constant amount of space to store the variables digits, count, start, N, num, idx, and s.
    //  Approach:
    //   1. We can first find the number of digits in the nth digit by iterating through the number of digits and counting how many digits are in each range (1-9, 10-99, 100-999, etc.) until we reach the range that contains  the nth digit.
    //   2. Once we have found the number of digits, we can calculate the starting number of that range and the index of the nth digit within that range.
    //   3. Finally, we can convert the starting number to a string and return the digit at the calculated index.
    int findNthDigit(int n)
    {
        long long digits = 1, count = 9, start = 1;
        long long N = n;
        while (N > digits * count)
        {
            N -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }
        long long num = start + (N - 1) / digits;
        int idx = (N - 1) % digits;
        string s = to_string(num);
        return s[idx] - '0';
    }
};
