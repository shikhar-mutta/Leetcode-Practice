// Link: https://leetcode.com/problems/brace-expansion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<char>> groups;
        int i = 0, n = s.size();
        while (i < n) {
            vector<char> group;
            if (s[i] == '{') {
                i++;
                while (s[i] != '}') {
                    if (s[i] != ',') group.push_back(s[i]);
                    i++;
                }
                i++;
            } else {
                group.push_back(s[i]);
                i++;
            }
            sort(group.begin(), group.end());
            groups.push_back(group);
        }

        vector<string> res;
        string cur;
        backtrack(groups, 0, cur, res);
        return res;
    }

private:
    void backtrack(vector<vector<char>>& groups, int idx, string& cur, vector<string>& res) {
        if (idx == (int)groups.size()) { res.push_back(cur); return; }
        for (char c : groups[idx]) {
            cur.push_back(c);
            backtrack(groups, idx + 1, cur, res);
            cur.pop_back();
        }
    }
};
