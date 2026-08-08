// Link: https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int freqA[26] = {0}, freqB[26] = {0};
        for (char c : a) freqA[c - 'a']++;
        for (char c : b) freqB[c - 'a']++;

        int best = INT_MAX;
        // condition 3: make all chars equal (pick best char)
        for (int c = 0; c < 26; c++) {
            best = min(best, (int)a.size() - freqA[c] + (int)b.size() - freqB[c]);
        }

        // condition 1: every char in a < every char in b (threshold split)
        // condition 2: every char in b < every char in a (swap a,b)
        auto solveOneWay = [&](int freq1[26], int freq2[26]) {
            int localBest = INT_MAX;
            for (int t = 0; t < 26; t++) {
                int cost = 0;
                for (int c = 0; c < 26; c++) {
                    if (c >= t) cost += freq1[c];
                    else cost += freq2[c];
                }
                localBest = min(localBest, cost);
            }
            return localBest;
        };

        best = min(best, solveOneWay(freqA, freqB));
        best = min(best, solveOneWay(freqB, freqA));

        return best;
    }
};
