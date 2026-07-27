// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k) SC: O(k)
// Approach: DP with 3 states per transaction count j: cash[j] (no open
// position, j transactions completed), long_[j] (holding a bought share
// as transaction j), short_[j] (holding a short-sold share as
// transaction j). Each day, either close a position (completing that
// transaction) or open a new long/short position starting transaction j
// from cash[j-1]. Answer is the best cash[j] over all j.
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = LLONG_MIN / 2;
        vector<long long> cash(k + 1, NEG), long_(k + 1, NEG), short_(k + 1, NEG);
        cash[0] = 0;

        for (int p : prices) {
            vector<long long> ncash = cash, nlong = long_, nshort = short_;
            for (int j = 1; j <= k; j++) {
                nlong[j] = max(long_[j], cash[j-1] - p);
                nshort[j] = max(short_[j], cash[j-1] + p);
            }
            for (int j = 0; j <= k; j++) {
                long long best = cash[j];
                if (long_[j] > NEG) best = max(best, long_[j] + p);
                if (short_[j] > NEG) best = max(best, short_[j] - p);
                ncash[j] = best;
            }
            cash = ncash; long_ = nlong; short_ = nshort;
        }

        long long ans = 0;
        for (int j = 0; j <= k; j++) ans = max(ans, cash[j]);
        return ans;
    }
};
