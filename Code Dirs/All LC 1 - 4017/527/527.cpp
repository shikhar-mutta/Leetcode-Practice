// Link: https://leetcode.com/problems/word-abbreviation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * len)  SC: O(n)
// Approach: for each prefix length, group words sharing the same abbreviation
// at that length; words uniquely abbreviated are finalized, conflicting
// groups retry with one more prefix char, repeat until all resolved
class Solution {
    string abbreviate(const string& w, int prefixLen) {
        int n = w.size();
        int midLen = n - prefixLen - 1;
        if (midLen <= 1) return w;
        string abbr = w.substr(0, prefixLen) + to_string(midLen) + w.back();
        return abbr.size() < w.size() ? abbr : w;
    }

public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        vector<int> prefixLen(n, 1);
        vector<string> res(n);

        vector<int> pending(n);
        iota(pending.begin(), pending.end(), 0);

        while (!pending.empty()) {
            unordered_map<string, vector<int>> groups;
            for (int i : pending) {
                string abbr = abbreviate(words[i], prefixLen[i]);
                groups[abbr].push_back(i);
            }

            vector<int> next;
            for (auto& [abbr, idxs] : groups) {
                if (idxs.size() == 1) {
                    res[idxs[0]] = abbr;
                } else {
                    for (int i : idxs) {
                        prefixLen[i]++;
                        next.push_back(i);
                    }
                }
            }
            pending = next;
        }
        return res;
    }
};
