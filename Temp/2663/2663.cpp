// Link: https://leetcode.com/problems/lexicographically-smallest-beautiful-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(string &s, int pos, char c) {
        if (pos >= 1 && s[pos-1] == c) return false;
        if (pos >= 2 && s[pos-2] == c) return false;
        return true;
    }

    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        char maxChar = 'a' + k - 1;
        int i = n - 1;

        while (i >= 0) {
            char c = s[i] + 1;
            bool found = false;
            while (c <= maxChar) {
                if (ok(s, i, c)) { found = true; break; }
                c++;
            }
            if (found) {
                s[i] = c;
                for (int j = i + 1; j < n; j++) {
                    char v = 'a';
                    while (!ok(s, j, v)) v++;
                    s[j] = v;
                }
                return s;
            }
            i--;
        }
        return "";
    }
};
