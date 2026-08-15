// Link: https://leetcode.com/problems/find-the-original-typed-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        const long long MOD = 1000000007;
        int n = word.size();
        vector<int> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            runs.push_back(j - i);
            i = j;
        }

        long long totalProduct = 1;
        for (int L : runs) totalProduct = totalProduct * L % MOD;

        if (k <= 1) return (int)totalProduct; // every config has length >= 1 (trivially >= k when k<=1)

        // dp[s] = number of ways to pick reduced lengths (>=1 per run) summing to exactly s, for s=0..k-1
        vector<long long> dpV(k, 0), ndpV(k, 0), prefixV(k + 1, 0);
        long long* dp = dpV.data();
        long long* ndp = ndpV.data();
        long long* prefix = prefixV.data();
        dp[0] = 1;

        // collapse consecutive length-1 runs into a single batched shift operation
        vector<pair<int,int>> batched; // (L, count)
        for (int L : runs) {
            if (L == 1 && !batched.empty() && batched.back().first == 1) {
                batched.back().second++;
            } else {
                batched.push_back({L, 1});
            }
        }

        for (auto& [L, cnt] : batched) {
            if (L == 1) {
                int m = min(cnt, k); // shifting by >=k just zeroes everything out
                for (int s = 0; s < k; s++) {
                    ndp[s] = (s >= m) ? dp[s - m] : 0;
                }
                std::swap(dp, ndp);
                continue;
            }
            // cnt should be 1 here (only length-1 runs are batched)
            prefix[0] = 0;
            for (int s = 0; s < k; s++) prefix[s+1] = prefix[s] + dp[s];
            int capL = L < k ? L : k;
            if (capL == k) {
                for (int s = 0; s < k; s++) ndp[s] = prefix[s] % MOD;
            } else {
                for (int s = 0; s < capL; s++) ndp[s] = prefix[s] % MOD;
                for (int s = capL; s < k; s++) ndp[s] = (prefix[s] - prefix[s - capL]) % MOD;
            }
            std::swap(dp, ndp);
        }

        long long lessThanK = 0;
        for (int s = 0; s < k; s++) lessThanK = (lessThanK + dp[s]) % MOD;

        long long ans = (totalProduct - lessThanK % MOD + MOD) % MOD;
        return (int)ans;
    }
};
