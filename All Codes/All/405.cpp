// Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        string hex = "0123456789abcdef";
        string res;
        while (num && res.size() < 8)
        { // num & 0xf gives the last 4 bits of num, which corresponds to a single hexadecimal digit
            res += hex[num & 0xf];
            num >>= 4; // Right shift (divide by 16)
        }
        // Reverse the string to get the correct order of hexadecimal digits
        reverse(res.begin(), res.end());
        return res;
    }
};
