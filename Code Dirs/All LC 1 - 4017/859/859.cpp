// Link: https://leetcode.com/problems/buddy-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) {
            vector<int> cnt(26, 0);
            for (char c : s) if (++cnt[c-'a'] > 1) return true;
            return false;
        }
        vector<int> diff;
        for (int i = 0; i < (int)s.size(); i++)
            if (s[i] != goal[i]) diff.push_back(i);
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};
