// Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        const int NONE = 26;
        auto dist = [&](int a, int b) {
            if (a == NONE) return 0;
            int r1 = a / 6, c1 = a % 6, r2 = b / 6, c2 = b % 6;
            return abs(r1 - r2) + abs(c1 - c2);
        };

        vector<int> dp(27, INT_MAX);
        dp[NONE] = 0;

        for (int i = 0; i < n; i++) {
            int cur = word[i] - 'A';
            int prevActive = (i == 0) ? NONE : (word[i-1] - 'A');
            vector<int> next(27, INT_MAX);

            for (int o = 0; o < 27; o++) {
                if (dp[o] == INT_MAX) continue;
                // switch: use finger at o to type cur; prevActive becomes idle
                int cand1 = dp[o] + dist(o, cur);
                if (cand1 < next[prevActive]) next[prevActive] = cand1;

                // continue: use finger at prevActive to type cur; o stays idle
                if (prevActive != NONE) {
                    int cand2 = dp[o] + dist(prevActive, cur);
                    if (cand2 < next[o]) next[o] = cand2;
                }
            }
            dp = next;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
