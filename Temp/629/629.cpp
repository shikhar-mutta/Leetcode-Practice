// Link: https://leetcode.com/problems/k-inverse-pairs-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k) SC: O(k)
// Approach: dp[i][j] = number of permutations of 1..i with j inverse pairs = sum of dp[i-1][j-i+1..j] (placing element i in one of i positions). Use prefix sums to compute the window sum in O(1).
class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9+7;
        vector<int> dp(k+1, 0), prefix(k+2, 0);
        dp[0] = 1;
        for (int i = 0; i < k+2; i++) prefix[i] = (i>0 ? prefix[i-1] : 0) + (i<=k ? dp[i] : 0);
        for (int i = 1; i <= n; i++) {
            vector<int> ndp(k+1, 0);
            vector<int> pre(k+2, 0);
            for (int j = 0; j <= k; j++) pre[j+1] = (pre[j] + dp[j]) % MOD;
            for (int j = 0; j <= k; j++) {
                int hi = j;
                int lo = j - i + 1;
                int sum;
                if (lo < 0) sum = pre[hi+1];
                else sum = (pre[hi+1] - pre[lo] + MOD) % MOD;
                ndp[j] = sum;
            }
            dp = ndp;
        }
        return dp[k];
    }
};
