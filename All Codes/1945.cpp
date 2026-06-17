// Link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*k) and SC: O(n)
    int getLucky(string s, int k)
    {
        // step 1: replace each letter by its 1-based position, concatenate the digits
        string digits;
        for (char c : s)
            digits += to_string(c - 'a' + 1);

        // step 2: sum the digits, repeated k times
        int num = 0;
        while (k--)
        {
            int sum = 0;
            for (char d : digits)
                sum += d - '0';
            num = sum;
            digits = to_string(sum); // feed the sum back in for the next round
        }
        return num;
    }
};
