// Link: https://leetcode.com/problems/number-of-lines-to-write-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: accumulate width per line; when adding the next char would exceed 100, start a new line.
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, cur = 0;
        for (char c : s) {
            int w = widths[c-'a'];
            if (cur + w > 100) { lines++; cur = w; }
            else cur += w;
        }
        return {lines, cur};
    }
};
