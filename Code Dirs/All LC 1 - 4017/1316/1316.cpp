// Link: https://leetcode.com/problems/distinct-echo-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        unordered_set<string> seen;
        for (int len = 1; len * 2 <= n; len++) {
            int matchLen = 0;
            for (int i = 0; i + len < n; i++) {
                if (text[i] == text[i + len]) matchLen++;
                else matchLen = 0;
                if (matchLen >= len) {
                    seen.insert(text.substr(i - len + 1, len));
                }
            }
        }
        return seen.size();
    }
};
