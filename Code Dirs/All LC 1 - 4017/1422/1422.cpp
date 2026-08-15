// Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s) if (c == '1') ones++;

        int zeros = 0, bestScore = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            bestScore = max(bestScore, zeros + ones);
        }
        return bestScore;
    }
};
