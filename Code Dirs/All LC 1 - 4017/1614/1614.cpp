// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, best = 0;
        for (char c : s) {
            if (c == '(') depth++;
            else if (c == ')') depth--;
            best = max(best, depth);
        }
        return best;
    }
};
