// Link: https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: simulate resource usage; when a deficit occurs, compute the
// number of top-up operations c in closed form (ceil(deficit/k)) instead
// of one-by-one, and add their cost via the arithmetic series formula
// sum_{i=prevOps+1}^{prevOps+c} i = c*prevOps + c*(c+1)/2, all mod 1e9+7.
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long resources = k;
        long long opsDone = 0;
        long long cost = 0;
        for (int x : nums) {
            long long need = (long long)x - resources;
            if (need > 0) {
                long long c = (need + k - 1) / k;
                long long add = ( (c % MOD) * (opsDone % MOD) % MOD
                                 + (c % MOD) * ((c + 1) % MOD) % MOD * 500000004LL % MOD ) % MOD;
                cost = (cost + add) % MOD;
                opsDone += c;
                resources += c * k;
            }
            resources -= x;
        }
        return (int)cost;
    }
};
