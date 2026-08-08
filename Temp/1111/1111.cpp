// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int depth = 0;
        for (char c : seq) {
            if (c == '(') {
                depth++;
                res.push_back((depth + 1) % 2);
            } else {
                res.push_back((depth + 1) % 2);
                depth--;
            }
        }
        return res;
    }
};
