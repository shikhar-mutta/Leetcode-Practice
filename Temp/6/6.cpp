// Link: https://leetcode.com/problems/zigzag-conversion/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: simulate the zigzag by bucketing chars into numRows rows, bouncing direction at the top/bottom row
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, (int)s.size()));
        int cur = 0, dir = -1;
        for (char c : s) {
            rows[cur] += c;
            if (cur == 0 || cur == numRows - 1) dir = -dir;
            cur += dir;
        }
        string res;
        for (auto& r : rows) res += r;
        return res;
    }
};
