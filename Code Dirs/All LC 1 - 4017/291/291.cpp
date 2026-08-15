// Link: https://leetcode.com/problems/word-pattern-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) worst case  SC: O(n)
// Approach: backtrack over pattern index / string position, maintaining a
// bijective map char->substring, trying every possible split length
class Solution {
    unordered_map<char, string> c2w;
    unordered_map<string, char> w2c;

    bool solve(const string& pattern, const string& s, int pi, int si) {
        if (pi == (int)pattern.size() && si == (int)s.size()) return true;
        if (pi == (int)pattern.size() || si == (int)s.size()) return false;

        char c = pattern[pi];
        if (c2w.count(c)) {
            string& w = c2w[c];
            if (s.compare(si, w.size(), w) != 0) return false;
            return solve(pattern, s, pi + 1, si + w.size());
        }

        for (int len = 1; si + len <= (int)s.size(); len++) {
            string w = s.substr(si, len);
            if (w2c.count(w)) continue;
            c2w[c] = w;
            w2c[w] = c;
            if (solve(pattern, s, pi + 1, si + len)) return true;
            c2w.erase(c);
            w2c.erase(w);
        }
        return false;
    }

public:
    bool wordPatternMatch(string pattern, string s) {
        return solve(pattern, s, 0, 0);
    }
};
