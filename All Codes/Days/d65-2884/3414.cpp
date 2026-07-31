// Link: https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long,4>> iv(n); // l, r, w, idx
        for (int i = 0; i < n; i++) iv[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        sort(iv.begin(), iv.end(), [](const array<long long,4>& a, const array<long long,4>& b){
            return a[1] < b[1];
        });

        struct State { long long w; vector<int> idxs; };
        vector<vector<State>> dp(n + 1, vector<State>(5, State{0, {}}));

        for (int i = 1; i <= n; i++) {
            long long l = iv[i-1][0], w = iv[i-1][2];
            int idx = (int)iv[i-1][3];
            // find count of intervals among first i-1 (sorted by r) with r < l
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (iv[mid][1] < l) lo = mid + 1; else hi = mid;
            }
            int j = lo; // dp[j] usable as prefix state

            for (int k = 0; k <= 4; k++) {
                State best = dp[i-1][k]; // skip
                if (k >= 1) {
                    State cand = dp[j][k-1];
                    cand.w += w;
                    auto pos = upper_bound(cand.idxs.begin(), cand.idxs.end(), idx);
                    cand.idxs.insert(pos, idx);
                    if (cand.w > best.w || (cand.w == best.w && cand.idxs < best.idxs)) best = cand;
                }
                dp[i][k] = best;
            }
        }

        return dp[n][4].idxs;
    }
};
