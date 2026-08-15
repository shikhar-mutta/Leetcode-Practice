// Link: https://leetcode.com/problems/domino-and-tromino-tiling/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: known recurrence f(n) = 2*f(n-1) + f(n-3), with f(0)=1, f(1)=1, f(2)=2, derived from full-column and partial-tromino states.
class Solution {
public:
    int numTilings(int n) {
        const long long MOD = 1e9+7;
        if (n <= 2) return n == 0 ? 1 : n;
        vector<long long> f(n+1);
        f[0] = 1; f[1] = 1; f[2] = 2;
        for (int i = 3; i <= n; i++) {
            f[i] = (2*f[i-1] % MOD + f[i-3]) % MOD;
        }
        return (int)f[n];
    }
};
