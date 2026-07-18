// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxDepth(string s)
    {
        int depth = 0, maxDepth = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (c == ')')
                depth--;
        }
        return maxDepth;
    }
};
