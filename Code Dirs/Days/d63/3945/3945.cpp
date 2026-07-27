// Link: https://leetcode.com/problems/digit-frequency-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: count frequency of each digit, sum d*freq(d).
class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = {};
        for (char c : to_string(n)) freq[c - '0']++;
        int score = 0;
        for (int d = 0; d < 10; d++) score += d * freq[d];
        return score;
    }
};
