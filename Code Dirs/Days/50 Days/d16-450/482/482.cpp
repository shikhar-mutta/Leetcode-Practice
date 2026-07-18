// Link: https://leetcode.com/problems/license-key-formatting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string licenseKeyFormatting(string s, int k)
    {
        int count = 0;
        string result = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != '-')
            {
                if (count > 0 && count % k == 0)
                {
                    result += '-';
                }
                result += toupper(s[i]);
                count++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
