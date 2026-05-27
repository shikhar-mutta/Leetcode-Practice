// Link: https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            bool unMach = false;
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i] || strs[j].length() < (i + 1))
                {
                    unMach = true;
                    break;
                }
            }
            if (unMach)
                break;
            ans += strs[0][i];
        }
        return ans;
    }
};