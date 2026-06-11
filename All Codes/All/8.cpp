// Link: https://leetcode.com/problems/string-to-integer-atoi/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size(), sg = 1;
        while (i < n && s[i] == ' ')
            i++;
        if (s[i] == '+' || s[i] == '-')
            sg = s[i] == '-' ? -1 : 1, i++;
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i++] - '0');
            if (ans > INT_MAX) // Early Stopping Condition
                break;
        }
        long long res = ans * sg;
        // int overflow & underflow conditions
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;

        return (int)res;
    }
};
