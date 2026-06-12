// Link: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string freqAlphabets(string s)
    {
        int n = s.length(), i = 0;
        string ans = "";

        while (i < n)
        {
            if (i + 2 < n && s[i + 2] == '#') // Two-digit number
            {
                int ss = (s[i] - '0') * 10 + (s[i + 1] - '0');
                ans += char(ss + 'a' - 1);
                i += 3;
            }
            else // Single-digit number
            {
                ans += char(s[i] - '0' - 1 + 'a');
                i++;
            }
        }

        return ans;
    }
};
