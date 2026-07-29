// Link: https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        vector<vector<int>> byHi(n + 1); // stores pair index
        vector<int> lo(m);
        for (int i = 0; i < m; i++) {
            int a = conflictingPairs[i][0], b = conflictingPairs[i][1];
            int l = min(a, b), h = max(a, b);
            lo[i] = l;
            byHi[h].push_back(i);
        }

        vector<long long> gain(m, 0);
        long long top1Val = 0, top2Val = 0;
        int top1Idx = -1;
        long long baseline = 0;

        for (int r = 1; r <= n; r++) {
            for (int idx : byHi[r]) {
                long long v = lo[idx];
                if (v > top1Val) {
                    top2Val = top1Val;
                    top1Val = v;
                    top1Idx = idx;
                } else if (v > top2Val) {
                    top2Val = v;
                }
            }
            baseline += (long long)r - top1Val;
            if (top1Idx != -1) gain[top1Idx] += top1Val - top2Val;
        }

        long long best = 0;
        for (int i = 0; i < m; i++) best = max(best, gain[i]);

        return baseline + best;
    }
};
