// Link: https://leetcode.com/problems/before-and-after-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        vector<string> firstWord(n), lastWord(n);
        for (int i = 0; i < n; i++) {
            int sp = phrases[i].find(' ');
            firstWord[i] = sp == (int)string::npos ? phrases[i] : phrases[i].substr(0, sp);
            int lsp = phrases[i].find_last_of(' ');
            lastWord[i] = lsp == (int)string::npos ? phrases[i] : phrases[i].substr(lsp + 1);
        }

        set<string> results;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (lastWord[i] == firstWord[j]) {
                    string combined = phrases[i] + phrases[j].substr(firstWord[j].size());
                    results.insert(combined);
                }
            }
        }
        return vector<string>(results.begin(), results.end());
    }
};
