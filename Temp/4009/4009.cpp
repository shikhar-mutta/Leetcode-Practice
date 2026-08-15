// Link: https://leetcode.com/problems/minimum-possible-maximum-waiting-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        int n = demand.size();
        int f0 = fuel[0], f1 = fuel[1];
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + demand[i];

        const int R = 21; // rel values 0..20
        const int INF = INT_MAX / 2;
        // dp[a0][r0][r1] = min possible max-wait-so-far
        vector<vector<vector<int>>> dp(f0 + 1, vector<vector<int>>(R, vector<int>(R, INF)));
        dp[0][0][0] = 0;

        int K = 0; // max index reachable (cars served)
        int bestAtK = 0;

        for (int i = 0; i <= n; i++) {
            // check reachability at this i
            bool reach = false;
            int bestHere = INF;
            for (int a0 = 0; a0 <= f0; a0++)
                for (int r0 = 0; r0 < R; r0++)
                    for (int r1 = 0; r1 < R; r1++)
                        if (dp[a0][r0][r1] < INF) {
                            reach = true;
                            bestHere = min(bestHere, dp[a0][r0][r1]);
                        }
            if (reach) { K = i; bestAtK = bestHere; }
            else break;

            if (i == n) break;

            vector<vector<vector<int>>> ndp(f0 + 1, vector<vector<int>>(R, vector<int>(R, INF)));
            int d = demand[i];
            long long assignedBeforeSum = prefix[i];
            for (int a0 = 0; a0 <= f0; a0++) {
                for (int r0 = 0; r0 < R; r0++) {
                    for (int r1 = 0; r1 < R; r1++) {
                        int cur = dp[a0][r0][r1];
                        if (cur >= INF) continue;
                        long long a1 = assignedBeforeSum - a0;
                        long long rem0 = f0 - a0;
                        long long rem1 = f1 - a1;
                        // option assign to dispenser 0
                        if (rem0 >= d) {
                            int wait = r0;
                            int newMax = max(cur, wait);
                            int na0 = a0 + d;
                            int nr0 = d;
                            int nr1 = max(0, r1 - r0);
                            if (na0 <= f0 && newMax < ndp[na0][nr0][nr1]) ndp[na0][nr0][nr1] = newMax;
                        }
                        // option assign to dispenser 1
                        if (rem1 >= d) {
                            int wait = r1;
                            int newMax = max(cur, wait);
                            int na0 = a0;
                            int nr1 = d;
                            int nr0 = max(0, r0 - r1);
                            if (newMax < ndp[na0][nr0][nr1]) ndp[na0][nr0][nr1] = newMax;
                        }
                    }
                }
            }
            dp = move(ndp);
        }

        if (K == 0) return -1;
        return bestAtK;
    }
};
