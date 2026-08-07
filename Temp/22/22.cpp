// Link: https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(4^n / sqrt(n))  SC: O(n) recursion depth (excluding output)
// Approach: backtracking, add '(' while open<n, add ')' while close<open
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        function<void(int,int)> bt = [&](int open, int close) {
            if ((int)cur.size() == 2 * n) { res.push_back(cur); return; }
            if (open < n) { cur += '('; bt(open + 1, close); cur.pop_back(); }
            if (close < open) { cur += ')'; bt(open, close + 1); cur.pop_back(); }
        };
        bt(0, 0);
        return res;
    }
};
