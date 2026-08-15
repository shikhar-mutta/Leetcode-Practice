// Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0, needClose = 0;
        for (char c : s) {
            if (c == '(') {
                if (needClose % 2 == 1) { insertions++; needClose--; }
                needClose += 2;
            } else {
                needClose--;
                if (needClose < 0) { insertions++; needClose = 1; }
            }
        }
        insertions += needClose;
        return insertions;
    }
};
