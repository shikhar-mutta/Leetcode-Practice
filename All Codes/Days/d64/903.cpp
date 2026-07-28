// Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: dp[j] after processing i characters = number of valid
// permutations of the first i+1 relative ranks whose last element is
// the (j+1)-th smallest among those i+1 values. Transition: for 'I' the
// next element must be larger, so new_dp[j] = sum of old dp[k] for
// k < j; for 'D' it must be smaller, so new_dp[j] = sum of old dp[k]
// for k >= j. Computed via prefix sums, all mod 1e9+7.
class Solution {
public:
    int numPermsDISequence(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(1, 1); // i=0: only 1 element, dp[0]=1

        for (int i = 0; i < n; i++) {
            int newSize = dp.size() + 1;
            vector<long long> ndp(newSize, 0);
            vector<long long> prefix(dp.size() + 1, 0);
            for (int k = 0; k < (int)dp.size(); k++) prefix[k + 1] = (prefix[k] + dp[k]) % MOD;

            for (int j = 0; j < newSize; j++) {
                if (s[i] == 'I') {
                    // sum of dp[k] for k < j, k in [0, dp.size()-1]
                    int hi = min(j, (int)dp.size());
                    ndp[j] = prefix[hi];
                } else {
                    // sum of dp[k] for k >= j, k in [0, dp.size()-1]
                    int lo = min(j, (int)dp.size());
                    ndp[j] = (prefix[dp.size()] - prefix[lo] + MOD) % MOD;
                }
            }
            dp = ndp;
        }
        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return (int)ans;
    }
};
