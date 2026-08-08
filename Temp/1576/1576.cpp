// Link: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'c'; c++) {
                    if ((i == 0 || s[i-1] != c) && (i == n-1 || s[i+1] != c)) {
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
