// Link: https://leetcode.com/problems/excel-sheet-column-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: base-26 positional value, digits 1-26 (A=1)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char c : columnTitle) res = res * 26 + (c - 'A' + 1);
        return res;
    }
};
