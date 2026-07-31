// Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<pair<char,int>> blocks;
        int i = 0;
        int totalOnes = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            blocks.push_back({s[i], j - i});
            if (s[i] == '1') totalOnes += j - i;
            i = j;
        }

        int m = blocks.size();
        int bestGain = 0;
        for (int k = 1; k < m - 1; k++) {
            if (blocks[k].first == '1') {
                int gain = blocks[k-1].second + blocks[k+1].second;
                bestGain = max(bestGain, gain);
            }
        }

        return totalOnes + bestGain;
    }
};
