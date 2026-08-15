// Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for (int i = 0; i < (int)s.size() && j < (int)t.size(); i++) {
            if (s[i] == t[j]) j++;
        }
        return t.size() - j;
    }
};
