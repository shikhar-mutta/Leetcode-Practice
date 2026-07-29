// Link: https://leetcode.com/problems/sum-of-beautiful-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        vector<vector<int>> divisorLists(maxVal + 1);
        for (int x : nums) {
            for (int i = 1; (long long)i * i <= x; i++) {
                if (x % i == 0) {
                    divisorLists[i].push_back(x);
                    int other = x / i;
                    if (other != i) divisorLists[other].push_back(x);
                }
            }
        }

        vector<long long> bit(maxVal + 2, 0);
        auto add = [&](int pos, long long delta) {
            for (; pos <= maxVal; pos += pos & (-pos)) bit[pos] = (bit[pos] + delta) % MOD;
        };
        auto query = [&](int pos) -> long long {
            long long s = 0;
            for (; pos > 0; pos -= pos & (-pos)) s = (s + bit[pos]) % MOD;
            return s;
        };

        vector<long long> countExactly(maxVal + 1, 0);
        long long answer = 0;

        for (int g = maxVal; g >= 1; g--) {
            if (divisorLists[g].empty()) continue;
            vector<pair<int,long long>> touched;
            long long f = 0;
            for (int v : divisorLists[g]) {
                long long sumLess = (v > 1) ? query(v - 1) : 0;
                long long ways = (sumLess + 1) % MOD;
                add(v, ways);
                touched.push_back({v, ways});
                f = (f + ways) % MOD;
            }
            for (auto& [pos, delta] : touched) add(pos, MOD - delta);

            long long sub = 0;
            for (int m = 2 * g; m <= maxVal; m += g) sub = (sub + countExactly[m]) % MOD;
            long long exact = ((f - sub) % MOD + MOD) % MOD;
            countExactly[g] = exact;
            answer = (answer + (long long)g % MOD * exact) % MOD;
        }

        return (int)answer;
    }
};
