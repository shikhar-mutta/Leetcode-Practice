// Link: https://leetcode.com/problems/reverse-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toBinary(int n)
    {
        string res = "";
        while (n > 0)
            res += (n % 2 == 0 ? "0" : "1"), n /= 2;

        if (res.length() < 32)
            res += string(32 - res.length(), '0');

        reverse(res.begin(), res.end());
        return res;
    }

    int reverseBits(int n)
    {
        string binary = toBinary(n);
        reverse(binary.begin(), binary.end());
        int result = 0;
        for (int i = 0; i < 32; i++)
            if (binary[i] == '1')
                result += (1 << (31 - i));

        return result;
    }
};
