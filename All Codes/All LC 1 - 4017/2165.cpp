// Link: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of digits in num.
    // SC: O(n) where n is the number of digits in num.
    // Approach:
    //   1. We will convert the number to a string and sort the digits in ascending order.
    //   2. If the number is negative, we will reverse the string to get the largest number.
    //   3. If the number is positive, we will check if the first digit is zero. If it is, we will find the first non-zero digit and swap it with the first digit.
    //   4. We will convert the string back to a number and return it.
    //   5. If the number is negative, we will return the negative of the number.
    //   6. If the number is positive, we will return the number.
    //   7. We will return the result.
    long long smallestNumber(long long num)
    {
        bool neg = num < 0;
        long long n = abs(num);
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        if (neg)
            reverse(digits.begin(), digits.end());
        else if (digits[0] == '0')
        {
            int j = 1;
            while (j < (int)digits.size() && digits[j] == '0')
                j++;
            if (j < (int)digits.size())
                swap(digits[0], digits[j]);
        }
        long long result = stoll(digits);
        return neg ? -result : result;
    }
};
