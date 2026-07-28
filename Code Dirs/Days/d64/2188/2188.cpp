// Link: https://leetcode.com/problems/minimum-time-to-finish-the-race/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(numLaps * maxRun)  SC: O(numLaps)
// Approach: for each tire compute cost to run L consecutive laps
// (f * r^0 + f*r^1 + ...), capping L around 20 since costs blow up past
// changeTime + f quickly. best[L] = min such cost across tires. Then DP:
// dp[i] = min over L<=min(i,cap) of dp[i-L] + (i-L>0 ? changeTime : 0) +
// best[L].
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        const int CAP = 20;
        vector<long long> best(CAP + 1, LLONG_MAX);
        for (auto& t : tires) {
            long long f = t[0], r = t[1];
            long long cur = 0, term = f;
            for (int L = 1; L <= CAP; L++) {
                cur += term;
                if (cur >= (long long)2e9) break;
                best[L] = min(best[L], cur);
                term *= r;
            }
        }
        vector<long long> dp(numLaps + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= numLaps; i++) {
            for (int L = 1; L <= min(i, CAP); L++) {
                if (best[L] == LLONG_MAX) continue;
                long long prev = dp[i - L];
                if (prev == LLONG_MAX) continue;
                long long cost = prev + best[L] + (i - L > 0 ? changeTime : 0);
                dp[i] = min(dp[i], cost);
            }
        }
        return (int)dp[numLaps];
    }
};
