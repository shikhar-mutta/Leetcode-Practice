// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, add = 0;
        for (char c : s) {
            if (c == '(') open++;
            else {
                if (open > 0) open--;
                else add++;
            }
        }
        return add + open;
    }
};
