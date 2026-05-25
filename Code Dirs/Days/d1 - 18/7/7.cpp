// Link: https://leetcode.com/problems/reverse-integer/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        // to string
        string s = to_string(x);

        // check for negative
        bool neg = false;
        if (s[0] == '-')
        {
            neg = true;
            s = s.substr(1);
        }

        /// reverse the string
        std::reverse(s.begin(), s.end());

        // remove leading zeros
        while (s.size() > 1 && s[0] == '0')
            s.erase(s.begin());

        // convert back to number
        long long num = stoll(s);

        // add negative sign back if needed
        if (neg)
            num = -num;

        // check for overflow
        if (num < INT_MIN || num > INT_MAX)
            return 0;

        // return the reversed number
        return (int)num;
    }
};