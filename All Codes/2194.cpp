// Link: https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        // s = "<col1><row1>:<col2><row2>"
        vector<string> res;
        // columns outer, rows inner -> output sorted by column then row
        for (char c = s[0]; c <= s[3]; c++)
            for (char r = s[1]; r <= s[4]; r++)
                res.push_back(string(1, c) + r);
        return res;
    }
};
