// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == 'a') i++;
        if (i == n) { s[n-1] = 'z'; return s; }
        int j = i;
        while (j < n && s[j] != 'a') { s[j]--; j++; }
        return s;
    }
};
