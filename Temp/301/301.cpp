// Link: https://leetcode.com/problems/remove-invalid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n)  SC: O(2^n)
// Approach: BFS over strings formed by removing one char at a time, stop at
// the first level where a valid string is found (guarantees minimal removals)
class Solution {
    bool isValid(const string& s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else if (c == ')') { bal--; if (bal < 0) return false; }
        }
        return bal == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited{s};
        queue<string> q;
        q.push(s);
        vector<string> res;
        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (isValid(cur)) {
                    res.push_back(cur);
                    found = true;
                    continue;
                }
                if (found) continue;
                for (int j = 0; j < (int)cur.size(); j++) {
                    if (cur[j] != '(' && cur[j] != ')') continue;
                    string next = cur.substr(0, j) + cur.substr(j + 1);
                    if (visited.insert(next).second) q.push(next);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
