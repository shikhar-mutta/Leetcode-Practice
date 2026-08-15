// Link: https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        int freq[10] = {0};
        for (char c : s) freq[c - '0']++;
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            char a = s[i], b = s[i + 1];
            if (a == b) continue;
            if (freq[a - '0'] == a - '0' && freq[b - '0'] == b - '0') {
                return s.substr(i, 2);
            }
        }
        return "";
    }
};
