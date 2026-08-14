// Link: https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));
        for (int z = 1; z <= min(zero, limit); z++) dp0[z][0] = 1;
        for (int o = 1; o <= min(one, limit); o++) dp1[0][o] = 1;

        for (int z = 1; z <= zero; z++) {
            for (int o = 1; o <= one; o++) {
                long long val0 = (dp0[z-1][o] + dp1[z-1][o]) % MOD;
                if (z - limit - 1 >= 0) val0 -= dp1[z-limit-1][o];
                dp0[z][o] = ((val0 % MOD) + MOD) % MOD;

                long long val1 = (dp0[z][o-1] + dp1[z][o-1]) % MOD;
                if (o - limit - 1 >= 0) val1 -= dp0[z][o-limit-1];
                dp1[z][o] = ((val1 % MOD) + MOD) % MOD;
            }
        }
        return (int)((dp0[zero][one] + dp1[zero][one]) % MOD);
    }
};
