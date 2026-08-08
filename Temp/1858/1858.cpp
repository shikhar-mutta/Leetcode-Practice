// Link: https://leetcode.com/problems/longest-word-with-all-prefixes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        string best = "";
        for (auto& w : words) {
            bool valid = true;
            for (int len = 1; len <= (int)w.size(); len++) {
                if (!wordSet.count(w.substr(0, len))) { valid = false; break; }
            }
            if (valid) {
                if (w.size() > best.size() || (w.size() == best.size() && w < best)) {
                    best = w;
                }
            }
        }
        return best;
    }
};
