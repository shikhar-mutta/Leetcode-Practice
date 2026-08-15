// Link: https://leetcode.com/problems/adding-spaces-to-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        res.reserve(s.size() + spaces.size());
        int si = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (si < (int)spaces.size() && spaces[si] == i) {
                res += ' ';
                si++;
            }
            res += s[i];
        }
        return res;
    }
};
