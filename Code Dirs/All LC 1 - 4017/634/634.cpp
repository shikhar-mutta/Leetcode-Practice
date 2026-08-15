// Link: https://leetcode.com/problems/find-the-derangement-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: D(n) = (n-1) * (D(n-1) + D(n-2)), with D(0)=1, D(1)=0. Compute iteratively mod 1e9+7.
class Solution {
public:
    int findDerangement(int n) {
        const long long MOD = 1e9+7;
        if (n == 0) return 1;
        if (n == 1) return 0;
        long long d0 = 1, d1 = 0, d2;
        for (int i = 2; i <= n; i++) {
            d2 = ((long long)(i-1) * ((d1 + d0) % MOD)) % MOD;
            d0 = d1;
            d1 = d2;
        }
        return (int)d1;
    }
};
