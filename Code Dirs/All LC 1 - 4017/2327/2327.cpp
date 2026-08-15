// Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long MOD = 1e9 + 7;
        vector<long long> cnt(n + 1, 0);
        cnt[1] = 1;
        long long window = 0;
        for (int d = 2; d <= n; d++) {
            if (d - delay >= 1) window = (window + cnt[d - delay]) % MOD;
            if (d - forget >= 1) window = (window - cnt[d - forget] + MOD) % MOD;
            cnt[d] = window;
        }
        long long total = 0;
        for (int d = max(1, n - forget + 1); d <= n; d++) total = (total + cnt[d]) % MOD;
        return (int)total;
    }
};
