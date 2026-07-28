// Link: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTransformable(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        vector<queue<int>> pos(10);
        for (int i = 0; i < n; i++) pos[s[i] - '0'].push(i);
        for (int i = 0; i < n; i++) {
            int c = t[i] - '0';
            if (pos[c].empty()) return false;
            int idx = pos[c].front();
            for (int d = 0; d < c; d++) {
                if (!pos[d].empty() && pos[d].front() < idx) return false;
            }
            pos[c].pop();
        }
        return true;
    }
};
