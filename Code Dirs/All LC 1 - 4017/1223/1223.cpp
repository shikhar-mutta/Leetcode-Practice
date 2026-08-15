// Link: https://leetcode.com/problems/dice-roll-simulation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const long long MOD = 1e9 + 7;
        // dp[face][streak] = ways
        vector<vector<long long>> dp(6, vector<long long>(16, 0));
        for (int f = 0; f < 6; f++) dp[f][1] = 1;

        for (int roll = 2; roll <= n; roll++) {
            vector<vector<long long>> ndp(6, vector<long long>(16, 0));
            for (int f = 0; f < 6; f++) {
                for (int s = 1; s <= rollMax[f]; s++) {
                    if (dp[f][s] == 0) continue;
                    for (int nf = 0; nf < 6; nf++) {
                        if (nf == f) {
                            if (s + 1 <= rollMax[f]) ndp[nf][s+1] = (ndp[nf][s+1] + dp[f][s]) % MOD;
                        } else {
                            ndp[nf][1] = (ndp[nf][1] + dp[f][s]) % MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }

        long long total = 0;
        for (int f = 0; f < 6; f++)
            for (int s = 1; s <= rollMax[f]; s++)
                total = (total + dp[f][s]) % MOD;
        return (int)total;
    }
};
