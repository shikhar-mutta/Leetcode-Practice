// Link: https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        for (int t = 1; ; t++) {
            int removed = t * k;
            if (removed >= n) return t;
            if (word.substr(removed) == word.substr(0, n - removed)) return t;
        }
    }
};
