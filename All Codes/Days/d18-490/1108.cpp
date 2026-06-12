// Link: https://leetcode.com/problems/defanging-an-ip-address/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string defangIPaddr(string address)
    {
        string ans;
        for (char c : address)
        {
            if (c == '.')
                ans += "[.]";
            else
                ans += c;
        }
        return ans;
    }
};
