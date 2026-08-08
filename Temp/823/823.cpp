// Link: https://leetcode.com/problems/binary-trees-with-factors/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: sort arr; dp[x] = number of trees rootable at value x. For each x, dp[x] starts at 1 (leaf); for each smaller factor pair (a,b) with a*b==x, dp[x] += dp[a]*dp[b]. Sum all dp values.
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const long long MOD = 1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        for (int x : arr) {
            long long ways = 1;
            for (int a : arr) {
                if (a >= x) break;
                if (x % a == 0 && dp.count(x / a)) {
                    ways = (ways + dp[a] * dp[x / a]) % MOD;
                }
            }
            dp[x] = ways;
        }
        long long total = 0;
        for (auto& [v, w] : dp) total = (total + w) % MOD;
        return (int)total;
    }
};
