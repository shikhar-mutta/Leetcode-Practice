// Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<pair<char,int>> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text[j] == text[i]) j++;
            runs.push_back({text[i], j - i});
            i = j;
        }
        unordered_map<char,int> total;
        for (char c : text) total[c]++;

        int best = 0;
        for (int idx = 0; idx < (int)runs.size(); idx++) {
            auto [c, len] = runs[idx];
            int cand = len + (total[c] > len ? 1 : 0);
            best = max(best, cand);
            if (idx + 2 < (int)runs.size() && runs[idx+1].second == 1 && runs[idx+2].first == c) {
                int combined = len + runs[idx+2].second;
                cand = combined + (total[c] > combined ? 1 : 0);
                best = max(best, cand);
            }
        }
        return best;
    }
};
