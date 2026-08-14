// Link: https://leetcode.com/problems/construct-string-with-minimum-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        const unsigned long long MOD = 1000000000000000003ULL;
        const unsigned long long BASE = 131542391;
        int n = target.size();

        vector<unsigned long long> pw(n + 1), prefHash(n + 1, 0);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) pw[i] = (__uint128_t)pw[i-1] * BASE % MOD;
        for (int i = 0; i < n; i++)
            prefHash[i+1] = ((__uint128_t)prefHash[i] * BASE + target[i]) % MOD;

        auto substrHash = [&](int l, int len) -> unsigned long long {
            // hash of target[l .. l+len-1]
            unsigned long long h = ( (__uint128_t)MOD + prefHash[l+len] - (__uint128_t)prefHash[l] * pw[len] % MOD ) % MOD;
            return h;
        };

        unordered_map<int, unordered_map<unsigned long long, int>> byLength;
        for (int i = 0; i < (int)words.size(); i++) {
            int len = words[i].size();
            unsigned long long h = 0;
            for (char c : words[i]) h = ((__uint128_t)h * BASE + c) % MOD;
            auto& mp = byLength[len];
            auto it = mp.find(h);
            if (it == mp.end() || it->second > costs[i]) mp[h] = costs[i];
        }

        vector<int> lengths;
        for (auto& [len, mp] : byLength) lengths.push_back(len);

        const int INF = INT_MAX / 2;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] >= INF) continue;
            for (int len : lengths) {
                if (i + len > n) continue;
                unsigned long long h = substrHash(i, len);
                auto& mp = byLength[len];
                auto it = mp.find(h);
                if (it != mp.end()) {
                    dp[i+len] = min(dp[i+len], dp[i] + it->second);
                }
            }
        }
        return dp[n] >= INF ? -1 : dp[n];
    }
};
