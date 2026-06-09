// Link: https://leetcode.com/problems/excel-sheet-column-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int titleToNumber(string columnTitle)
    {
        int n = columnTitle.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }
        return ans;
    }
};
