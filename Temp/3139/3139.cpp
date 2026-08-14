// Link: https://leetcode.com/problems/minimum-cost-to-equalize-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    // O(1) cost evaluation using precomputed sum, avoiding an O(n) scan per T
    __int128 costForFast(long long sumNums, int n, long long T, long long cost1, long long cost2, long long minV) {
        __int128 S = (__int128)n * T - sumNums;
        long long maxNeed = T - minV;
        if (cost2 >= 2 * cost1) {
            return S * cost1;
        }
        if ((__int128)maxNeed * 2 <= S) {
            __int128 pairs = S / 2;
            __int128 rem = S % 2;
            return pairs * cost2 + rem * cost1;
        } else {
            __int128 rem = 2 * (__int128)maxNeed - S;
            __int128 pairs = S - maxNeed;
            return pairs * cost2 + rem * cost1;
        }
    }

    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        long long minV = *min_element(nums.begin(), nums.end());
        long long maxV = *max_element(nums.begin(), nums.end());
        long long sumNums = 0;
        for (int x : nums) sumNums += x;

        // The cost is piecewise-linear in T across two regimes ("one element
        // dominates" vs "spread across pairs"), with the spread regime always
        // non-decreasing in T. So the true minimum is at T = maxV or at the
        // transition point between regimes (up to integer rounding/parity).
        vector<long long> candidates = {maxV, maxV + 1, maxV + 2};
        if (n != 2) {
            // transition where 2*maxNeed == S: T = (sumNums - 2*minV) / (n - 2)
            __int128 num = (__int128)sumNums - 2 * minV;
            long long denom = n - 2;
            long long tStar = (long long)(num / denom);
            for (long long d = -3; d <= 3; d++) {
                long long cand = tStar + d;
                if (cand >= maxV) candidates.push_back(cand);
            }
        }

        __int128 best = (__int128)1 << 120;
        for (long long T : candidates) {
            __int128 c = costForFast(sumNums, n, T, cost1, cost2, minV);
            if (c < best) best = c;
        }
        long long bestMod = (long long)(best % MOD);
        return (int)bestMod;
    }
};
