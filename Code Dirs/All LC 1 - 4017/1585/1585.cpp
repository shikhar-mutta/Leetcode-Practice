// Link: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTransformable(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<queue<int>> positions(10);
        for (int i = 0; i < (int)s.size(); i++) positions[s[i] - '0'].push(i);

        for (char c : t) {
            int d = c - '0';
            if (positions[d].empty()) return false;
            int pos = positions[d].front();
            for (int smaller = 0; smaller < d; smaller++) {
                if (!positions[smaller].empty() && positions[smaller].front() < pos) return false;
            }
            positions[d].pop();
        }
        return true;
    }
};
