// Link: https://leetcode.com/problems/minimum-operations-to-make-character-frequencies-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeStringGood(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        int maxF = *max_element(freq, freq + 26);

        int best = INT_MAX;
        for (int T = 0; T <= maxF; T++) {
            int cost = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] == 0) continue;
                cost += min(freq[i], abs(freq[i] - T));
            }
            best = min(best, cost);
        }
        return best;
    }
};
