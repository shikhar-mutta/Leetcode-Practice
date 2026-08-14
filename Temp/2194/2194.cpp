// Link: https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c1 = s[0], r1 = s[1], c2 = s[3], r2 = s[4];
        vector<string> res;
        for (char c = c1; c <= c2; c++) {
            for (char r = r1; r <= r2; r++) {
                res.push_back(string(1, c) + string(1, r));
            }
        }
        return res;
    }
};
