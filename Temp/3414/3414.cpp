// Link: https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        long long score;
        vector<int> list; // sorted ascending original indices
    };

    static bool better(const State& a, const State& b) {
        // true if a is strictly better than b
        if (a.score != b.score) return a.score > b.score;
        return a.list < b.list; // lexicographically smaller list wins
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> L(n), R(n), W(n);
        vector<int> origIdx(n);
        for (int i = 0; i < n; i++) {
            L[i] = intervals[idx[i]][0];
            R[i] = intervals[idx[i]][1];
            W[i] = intervals[idx[i]][2];
            origIdx[i] = idx[i];
        }

        // p[i] = number of usable prior intervals (in sorted order) with R < L[i]
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i; // search within [0, i-1]
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (R[mid] < L[i]) lo = mid + 1;
                else hi = mid;
            }
            // lo is first index with R[lo] >= L[i]; usable count = lo
            p[i] = lo;
        }

        vector<vector<State>> dp(n + 1, vector<State>(5, {0, {}}));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = {0, {}};
            for (int k = 1; k <= 4; k++) {
                State skip = dp[i - 1][k];
                State best = skip;

                State takeBase = dp[p[i - 1]][k - 1];
                State take;
                take.score = takeBase.score + W[i - 1];
                take.list = takeBase.list;
                take.list.insert(upper_bound(take.list.begin(), take.list.end(), origIdx[i - 1]), origIdx[i - 1]);

                if (better(take, best)) best = take;
                dp[i][k] = best;
            }
        }

        return dp[n][4].list;
    }
};
