// Link: https://leetcode.com/problems/minimum-operations-to-achieve-at-least-k-peaks/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*k)  SC: O(k)
// Approach: array is circular; a peak's neighbors can never themselves be
// peaks, so the cost to make index i a peak (raise it above both neighbors,
// only increments allowed) is independent of other choices: cost[i] =
// max(0, max(nums[prev],nums[next])+1 - nums[i]). Max achievable peaks is
// n/2; beyond that it's impossible. Reduce the circular "choose exactly k
// non-adjacent indices minimizing total cost" to two linear subproblems
// (forbid index 0, or forbid index n-1, since a valid circular non-adjacent
// set can't include both ends), each solved via standard non-adjacent-
// selection DP with rolling rows.
class Solution {
    long long solveLinear(vector<long long>& cost, int l, int r, int k) {
        int m = r - l + 1;
        const long long INF = LLONG_MAX / 2;
        if (m <= 0) return k == 0 ? 0 : INF;
        if (k > (m + 1) / 2) return INF;

        vector<long long> dpPrev2(k + 1, INF), dpPrev1(k + 1, INF), dpCur(k + 1, INF);
        dpPrev2[0] = 0;
        dpPrev1[0] = 0;

        for (int i = 1; i <= m; i++) {
            dpCur[0] = 0;
            long long c = cost[l + i - 1];
            for (int j = 1; j <= k; j++) {
                long long best = dpPrev1[j];
                long long takeBase = (i >= 2) ? dpPrev2[j-1] : (j - 1 == 0 ? 0 : INF);
                if (takeBase < INF) best = min(best, takeBase + c);
                dpCur[j] = best;
            }
            dpPrev2 = dpPrev1;
            dpPrev1 = dpCur;
        }
        return dpPrev1[k];
    }
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        if (k > n / 2) return -1;

        auto prevIdx = [&](int i) { return i > 0 ? i - 1 : n - 1; };
        auto nextIdx = [&](int i) { return i < n - 1 ? i + 1 : 0; };

        vector<long long> cost(n);
        for (int i = 0; i < n; i++) {
            long long need = max(nums[prevIdx(i)], nums[nextIdx(i)]) + 1LL;
            cost[i] = max(0LL, need - nums[i]);
        }

        const long long INF = LLONG_MAX / 2;
        long long caseA = solveLinear(cost, 1, n - 1, k);
        long long caseB = solveLinear(cost, 0, n - 2, k);
        long long ans = min(caseA, caseB);
        return ans >= INF ? -1 : (int)ans;
    }
};
