// Link: https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string maximumXor(string &s, string &t)
    {
        int n = s.size(), one = 0;
        for (char &ch : t) // Count the number of '1's in string t
            one += (ch == '1');
        int zero = n - one; // Determine the number of '0's in string t
        for (char &ch : s)
            if (ch == '0')
            {
                if (one > 0)
                    one--, ch = '1';
                else
                    zero--;
            }
            else
            {
                if (zero > 0)
                    zero--;
                else
                    one--, ch = '0';
            }
        return s;
    }
};