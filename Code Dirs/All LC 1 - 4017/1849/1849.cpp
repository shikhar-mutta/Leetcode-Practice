// Link: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(const string& s, int pos, long long prev) {
        if (pos == (int)s.size()) return true;
        long long cur = 0;
        for (int i = pos; i < (int)s.size(); i++) {
            cur = cur * 10 + (s[i] - '0');
            if (cur >= prev) break;
            if (cur == prev - 1 && dfs(s, i + 1, cur)) return true;
        }
        return false;
    }

    bool splitString(string s) {
        int n = s.size();
        long long first = 0;
        for (int i = 0; i < n - 1; i++) {
            first = first * 10 + (s[i] - '0');
            if (dfs(s, i + 1, first)) return true;
        }
        return false;
    }
};
