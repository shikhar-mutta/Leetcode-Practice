// Link: https://leetcode.com/problems/match-substring-after-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*M), SC: O(1)
// Approach: allowed[from][to] set from mappings; slide sub over s, each pos matches if equal or (sub[j],s[i+j]) allowed.
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool allowed[128][128] = {};
        for (auto& m : mappings) allowed[(int)m[0]][(int)m[1]] = true;
        int n = s.size(), m = sub.size();
        for (int i = 0; i + m <= n; i++) {
            bool ok = true;
            for (int j = 0; j < m && ok; j++) {
                char a = sub[j], b = s[i+j];
                if (a != b && !allowed[(int)a][(int)b]) ok = false;
            }
            if (ok) return true;
        }
        return false;
    }
};
