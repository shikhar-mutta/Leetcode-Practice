// Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: dp[i] = number of people who FIRST learn the secret on day i.
// Maintain a running "sharing" total = people currently able to spread it;
// each day, add in whoever started sharing today (learned `delay` days
// ago) and remove whoever forgets today (learned `forget` days ago) -
// dp[i] equals that updated sharing total, since every currently-sharing
// person spreads to exactly one new person per day. The final answer sums
// dp[i] over the last `forget` days (everyone who hasn't forgotten yet by
// day n).
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long MOD = 1000000007;
        vector<long long> dp(n + 1, 0); // dp[i] = people who learn on day i
        dp[1] = 1;

        long long sharing = 0; // people currently able to share
        for (int i = 2; i <= n; ++i) {
            // someone who learned on day (i - delay) starts sharing today
            if (i - delay >= 1)
                sharing = (sharing + dp[i - delay]) % MOD;
            // someone who learned on day (i - forget) forgets today, stops
            // sharing
            if (i - forget >= 1)
                sharing = (sharing - dp[i - forget] + MOD) % MOD;
            dp[i] = sharing;
        }

        // total who still remember on day n: learned within the last 'forget'
        // days
        long long total = 0;
        for (int i = n - forget + 1; i <= n; ++i)
            if (i >= 1)
                total = (total + dp[i]) % MOD;
        return (int)total;
    }
};
