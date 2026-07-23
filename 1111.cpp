// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;
        for (char c : seq) {
            if (c == '(') {
                ans.push_back(depth % 2);   // depth before opening
                depth++;
            } else {
                depth--;
                ans.push_back(depth % 2);   // depth after closing
            }
        }
        return ans;
    }
};