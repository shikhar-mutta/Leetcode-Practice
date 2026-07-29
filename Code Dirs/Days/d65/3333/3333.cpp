// Link: https://leetcode.com/problems/find-the-original-typed-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + numRuns*k), SC: O(k)
// Approach: split word into runs of length L_1..L_m; each run's original length independently
// ranges [1,L_i], giving total = prod(L_i) possible originals. Subtract those shorter than k:
// with e_i = (chosen length - 1) in [0, L_i-1], we need count of ways sum(e_i) < k - m. Runs
// with L_i==1 contribute no choice (e_i fixed at 0); for the rest, bounded-count DP via the
// classic sliding-window-prefix-sum trick processes each run in O(k) regardless of its length.
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const long long MOD = 1e9+7;
        int n = word.size();
        vector<int> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            runs.push_back(j - i);
            i = j;
        }
        int m = runs.size();

        long long total = 1;
        for (int L : runs) total = total * L % MOD;

        long long T = (long long)k - m;
        if (T <= 0) return (int)total;
        if (T > 200000) T = 200000; // safety cap, k<=2000 per constraints so unreachable

        vector<long long> dp(T, 0);
        dp[0] = 1;
        for (int L : runs) {
            if (L <= 1) continue;
            long long bound = min((long long)(L - 1), T - 1);
            vector<long long> ndp(T, 0);
            long long windowSum = 0;
            for (int s = 0; s < T; s++) {
                windowSum = (windowSum + dp[s]) % MOD;
                if (s - bound - 1 >= 0) windowSum = (windowSum - dp[s - bound - 1] + MOD) % MOD;
                ndp[s] = windowSum;
            }
            dp = ndp;
        }

        long long countBelow = 0;
        for (int s = 0; s < T; s++) countBelow = (countBelow + dp[s]) % MOD;

        return (int)((total - countBelow + MOD) % MOD);
    }
};
