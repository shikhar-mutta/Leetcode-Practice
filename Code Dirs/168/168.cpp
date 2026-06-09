// Link: https://leetcode.com/problems/excel-sheet-column-title/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n). SC: O(1).
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            char c = 'A' + (columnNumber % 26);
            ans += c;
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
