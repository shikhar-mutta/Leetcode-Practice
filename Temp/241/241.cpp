// Link: https://leetcode.com/problems/different-ways-to-add-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(Catalan(n))  SC: O(Catalan(n))
// Approach: recursive divide-conquer, splitting at each operator and combining left x right results
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < (int)expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                auto left = diffWaysToCompute(expression.substr(0, i));
                auto right = diffWaysToCompute(expression.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
