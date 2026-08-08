// Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int best = 0;

    void dfs(string& s, int idx, unordered_set<string>& used) {
        if (idx == (int)s.size()) {
            best = max(best, (int)used.size());
            return;
        }
        if ((int)used.size() + (int)(s.size() - idx) <= best) return;
        for (int len = 1; idx + len <= (int)s.size(); len++) {
            string sub = s.substr(idx, len);
            if (!used.count(sub)) {
                used.insert(sub);
                dfs(s, idx + len, used);
                used.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        dfs(s, 0, used);
        return best;
    }
};
