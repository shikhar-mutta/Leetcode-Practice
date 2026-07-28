// Link: https://leetcode.com/problems/prefix-and-suffix-search/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sum(len^2)) build, O(len) per query  SC: O(sum(len^2))
// Approach: for each word at index idx, generate every (suffix, prefix)
// pair combined as "suffix#prefix" and map it to idx, overwriting on
// duplicates so the largest index always wins. f() is then a single
// hashmap lookup.
class WordFilter {
    unordered_map<string,int> combo;
public:
    WordFilter(vector<string>& words) {
        for (int idx = 0; idx < (int)words.size(); idx++) {
            string& w = words[idx];
            int n = w.size();
            for (int i = 0; i <= n; i++) {
                string suf = w.substr(i);
                for (int j = 0; j <= n; j++) {
                    string pre = w.substr(0, j);
                    combo[suf + "#" + pre] = idx;
                }
            }
        }
    }

    int f(string pref, string suff) {
        auto it = combo.find(suff + "#" + pref);
        return it == combo.end() ? -1 : it->second;
    }
};
