// Link: https://leetcode.com/problems/process-string-with-special-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) worst case (string can double) SC: O(2^n) worst case
// Approach: direct simulation. '*' removes the last char, '#' duplicates
// the current string, '%' reverses it, any lowercase letter is appended.
class Solution {
public:
    string processStr(string s) {
        string result;
        for (char c : s) {
            if (c == '*') { if (!result.empty()) result.pop_back(); }
            else if (c == '#') result += result;
            else if (c == '%') reverse(result.begin(), result.end());
            else result += c;
        }
        return result;
    }
};
