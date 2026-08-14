// Link: https://leetcode.com/problems/minimum-time-to-finish-the-race/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int maxK = min(numLaps, 20);
        vector<long long> minSingle(maxK + 1, LLONG_MAX);
        for (auto& tire : tires) {
            long long f = tire[0], r = tire[1];
            long long cur = f, cum = 0;
            for (int k = 1; k <= maxK; k++) {
                cum += cur;
                minSingle[k] = min(minSingle[k], cum);
                if (cur > (long long)1e9) break;
                cur *= r;
            }
        }

        vector<long long> dp(numLaps + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= numLaps; i++) {
            for (int j = 1; j <= min(i, maxK); j++) {
                if (minSingle[j] == LLONG_MAX) continue;
                long long cand = dp[i - j] + minSingle[j] + (i - j > 0 ? changeTime : 0);
                dp[i] = min(dp[i], cand);
            }
        }
        return (int)dp[numLaps];
    }
};
