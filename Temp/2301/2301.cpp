// Link: https://leetcode.com/problems/match-substring-after-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        set<pair<char,char>> allowed;
        for (auto& m : mappings) allowed.insert({m[0], m[1]});

        int n = s.size(), m = sub.size();
        for (int i = 0; i + m <= n; i++) {
            bool ok = true;
            for (int j = 0; j < m && ok; j++) {
                char a = sub[j], b = s[i + j];
                if (a != b && !allowed.count({a, b})) ok = false;
            }
            if (ok) return true;
        }
        return false;
    }
};
