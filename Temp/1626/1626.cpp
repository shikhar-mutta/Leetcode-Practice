// Link: https://leetcode.com/problems/best-team-with-no-conflicts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (ages[a] != ages[b]) return ages[a] < ages[b];
            return scores[a] < scores[b];
        });
        vector<int> dp(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = scores[idx[i]];
            for (int j = 0; j < i; j++) {
                if (scores[idx[j]] <= scores[idx[i]]) {
                    dp[i] = max(dp[i], dp[j] + scores[idx[i]]);
                }
            }
            best = max(best, dp[i]);
        }
        return best;
    }
};
