// Link: https://leetcode.com/problems/find-the-count-of-good-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int half = (n + 1) / 2;
        set<array<int,10>> multisets;

        vector<int> halfDigits(half);
        function<void(int)> rec = [&](int pos) {
            if (pos == half) {
                vector<int> full(n);
                for (int i = 0; i < half; i++) full[i] = halfDigits[i];
                for (int i = 0; i < n; i++) full[n-1-i] = full[i];
                long long val = 0;
                for (int i = 0; i < n; i++) val = val * 10 + full[i];
                if (val % k == 0) {
                    array<int,10> cnt{};
                    for (int d : full) cnt[d]++;
                    multisets.insert(cnt);
                }
                return;
            }
            int lo = (pos == 0) ? 1 : 0;
            for (int d = lo; d <= 9; d++) {
                halfDigits[pos] = d;
                rec(pos + 1);
            }
        };
        rec(0);

        vector<long long> fact(11);
        fact[0] = 1;
        for (int i = 1; i <= 10; i++) fact[i] = fact[i-1] * i;

        long long total = 0;
        for (auto& cnt : multisets) {
            long long denom = 1;
            for (int d = 0; d <= 9; d++) denom *= fact[cnt[d]];
            long long allPerm = fact[n] / denom;

            long long leadZeroPerm = 0;
            if (cnt[0] > 0) {
                array<int,10> cnt2 = cnt;
                cnt2[0]--;
                long long denom2 = 1;
                for (int d = 0; d <= 9; d++) denom2 *= fact[cnt2[d]];
                leadZeroPerm = fact[n-1] / denom2;
            }
            total += (allPerm - leadZeroPerm);
        }

        return total;
    }
};
