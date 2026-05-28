// Link: https://leetcode.com/problems/number-of-lines-to-write-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int lines = 1, width = 0;
        for (char c : s)
        {
            int wd = widths[c - 'a'];
            if (width + wd <= 100)
            {
                width += wd;
            }
            else
            {
                width = wd;
                lines++;
            }
        }
        return {lines, width};
    }
};
