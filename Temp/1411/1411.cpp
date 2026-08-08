// Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        long long aba = 6, abc = 6;
        for (int i = 2; i <= n; i++) {
            long long newAba = (aba * 3 + abc * 2) % MOD;
            long long newAbc = (aba * 2 + abc * 2) % MOD;
            aba = newAba;
            abc = newAbc;
        }
        return (int)((aba + abc) % MOD);
    }
};
