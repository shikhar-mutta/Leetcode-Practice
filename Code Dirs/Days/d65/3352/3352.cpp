// Link: https://leetcode.com/problems/count-k-reducible-numbers-less-than-n/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len^2), SC: O(len^2)
// Approach: precompute steps[p] = min operations to reduce a number with popcount p down to 1
// (steps[1]=0, steps[p]=1+steps[popcount(p)], well-defined bottom-up since popcount(p)<p). A
// number is k-reducible iff 1+steps[popcount(num)] <= k. Count, for each achievable popcount p,
// how many numbers in [0,N-1] have exactly p set bits via a standard binary digit-DP: whenever
// the target's bit is 1, branching to place 0 there and freely choosing the remaining bits
// contributes C(remaining, x) to popcount (ones-so-far + x) for every x. Sum counts over all p
// (excluding p=0, i.e. num=0) whose k-reducibility condition holds.
class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const long long MOD = 1e9+7;
        int len = s.size();

        vector<vector<long long>> C(len+1, vector<long long>(len+1, 0));
        for (int i = 0; i <= len; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + (j <= i-1 ? C[i-1][j] : 0)) % MOD;
        }

        vector<int> steps(len+1, -1);
        steps[1] = 0;
        for (int v = 2; v <= len; v++) {
            int pc = __builtin_popcount(v);
            steps[v] = 1 + steps[pc];
        }

        vector<long long> countPop(len+1, 0);
        int ones = 0;
        for (int i = 0; i < len; i++) {
            int remaining = len - 1 - i;
            if (s[i] == '1') {
                for (int x = 0; x <= remaining; x++) {
                    countPop[ones + x] = (countPop[ones + x] + C[remaining][x]) % MOD;
                }
                ones++;
            }
        }

        long long ans = 0;
        for (int p = 1; p <= len; p++) {
            if (countPop[p] == 0) continue;
            int need = 1 + steps[p];
            if (need <= k) ans = (ans + countPop[p]) % MOD;
        }
        return (int)ans;
    }
};
