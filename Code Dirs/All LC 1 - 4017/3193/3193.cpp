// Link: https://leetcode.com/problems/count-the-number-of-inversions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const long long MOD = 1e9 + 7;
        vector<int> req(n, -1);
        for (auto& r : requirements) req[r[0]] = r[1];
        if (req[0] != -1 && req[0] != 0) return 0;

        int maxK = req[n-1];
        if (maxK == -1) {
            maxK = 0;
            for (int i = 0; i < n; i++) if (req[i] > maxK) maxK = req[i];
            // also account for maximum possible inversions n*(n-1)/2 if unconstrained at end
            maxK = max(maxK, n * (n - 1) / 2);
        }
        vector<long long> dp(maxK + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            vector<long long> prefix(maxK + 2, 0);
            for (int k = 0; k <= maxK; k++) prefix[k+1] = (prefix[k] + dp[k]) % MOD;
            vector<long long> ndp(maxK + 1, 0);
            for (int k = 0; k <= maxK; k++) {
                int lo = max(0, k - i);
                long long sum = (prefix[k+1] - prefix[lo] + MOD) % MOD;
                ndp[k] = sum;
            }
            if (req[i] != -1) {
                for (int k = 0; k <= maxK; k++) if (k != req[i]) ndp[k] = 0;
            }
            dp = ndp;
        }
        long long ans = 0;
        for (int k = 0; k <= maxK; k++) ans = (ans + dp[k]) % MOD;
        return (int)ans;
    }
};
