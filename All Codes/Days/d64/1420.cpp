// Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * m^2 * k)  SC: O(m * k)
// Approach: dp[v][c] = number of arrays of the current length whose
// maximum so far is v, using exactly c "new max" events (search cost).
// Extending by one element: staying <= v keeps max/cost the same (v
// choices, since values 1..v all work); picking a new value w > (old
// max) becomes the new max and increases cost by 1. Base case: length 1
// arrays have max=v, cost=1 for each v in 1..m.
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));
        for (int v = 1; v <= m; v++) dp[v][1] = 1;

        for (int len = 2; len <= n; len++) {
            vector<vector<long long>> ndp(m + 1, vector<long long>(k + 1, 0));
            for (int v = 1; v <= m; v++) {
                for (int c = 1; c <= k; c++) {
                    // stay at max v: any of v values appended, cost unchanged
                    ndp[v][c] = (ndp[v][c] + dp[v][c] * v) % MOD;
                    // new max v: previous max was < v, cost was c-1
                    for (int prevMax = 1; prevMax < v; prevMax++) {
                        ndp[v][c] = (ndp[v][c] + dp[prevMax][c - 1]) % MOD;
                    }
                }
            }
            dp = ndp;
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) ans = (ans + dp[v][k]) % MOD;
        return (int)ans;
    }
};
