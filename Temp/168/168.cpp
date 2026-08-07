// Link: https://leetcode.com/problems/excel-sheet-column-title/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: base-26 with digits 1-26 (not 0-25) — decrement by 1 each step before taking the remainder
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            columnNumber--;
            res += (char)('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
