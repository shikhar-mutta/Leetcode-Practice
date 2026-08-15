// Link: https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> z(n, 0);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && word[z[i]] == word[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }

        for (int t = 1; ; t++) {
            int removed = t * k;
            if (removed >= n) return t;
            if (z[removed] >= n - removed) return t;
        }
    }
};
