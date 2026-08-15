// Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int totalOnes = count(s.begin(), s.end(), '1');

        vector<pair<char,int>> runs;
        int n = t.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int best = totalOnes;
        int m = runs.size();
        for (int k = 1; k + 1 < m; k++) {
            if (runs[k].first == '1') {
                int candidate = totalOnes + runs[k-1].second + runs[k+1].second;
                best = max(best, candidate);
            }
        }
        return best;
    }
};
