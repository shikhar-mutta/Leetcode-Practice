// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(n).
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, __gcd(str1.size(), str2.size()));
    }
};
