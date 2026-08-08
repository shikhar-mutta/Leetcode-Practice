// Link: https://leetcode.com/problems/pyramid-transition-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(exponential, bounded by 7^(n^2)) SC: O(n)
// Approach: build a map from 2-char pair to possible 3rd chars; recursively try to build the row above the current row one triple at a time, backtracking on failure; base case is a single-char row (apex reached).
class Solution {
    unordered_map<string, vector<char>> allowedMap;
    bool solve(const string& row) {
        if (row.size() == 1) return true;
        string above;
        return extend(row, above, 0);
    }
    bool extend(const string& row, string& above, int pos) {
        if (pos == (int)row.size() - 1) return solve(above);
        string key = row.substr(pos, 2);
        if (!allowedMap.count(key)) return false;
        for (char c : allowedMap[key]) {
            above.push_back(c);
            if (extend(row, above, pos+1)) return true;
            above.pop_back();
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) allowedMap[s.substr(0,2)].push_back(s[2]);
        return solve(bottom);
    }
};
