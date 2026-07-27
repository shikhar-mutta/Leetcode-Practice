// Link: https://leetcode.com/problems/divisible-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*sqrt(maxVal) + maxVal + C*n) SC: O(maxVal)
// Approach: for a fixed k, the optimal score is the max-subarray sum of
// the signed array (+nums[i] if k|nums[i], else -nums[i]) — classic
// Kadane, subarray must be non-empty. Only two kinds of k ever matter:
// any k that divides at least one array element (candidates collected
// via each element's divisors), or a k that divides none of them (all
// such k give an identical Kadane result — just the single largest
// negative-array value — so only the smallest such k needs checking for
// the tie-break). Try every candidate, keep the best (score, then
// smallest k), and return score*k mod 1e9+7.
class Solution {
    static const long long MOD = 1e9 + 7;
    long long kadane(vector<int>& nums, int k) {
        long long best = LLONG_MIN, cur = 0;
        bool started = false;
        for (int x : nums) {
            long long v = (x % k == 0) ? x : -x;
            if (!started) { cur = v; started = true; }
            else cur = max(v, cur + v);
            best = max(best, cur);
        }
        return best;
    }
public:
    int divisibleGame(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isDivisor(maxVal + 2, false);
        set<int> candidates;
        for (int x : nums) {
            for (int d = 1; (long long)d * d <= x; d++) {
                if (x % d != 0) continue;
                int d1 = d, d2 = x / d;
                if (d1 > 1) { candidates.insert(d1); isDivisor[d1] = true; }
                if (d2 > 1) { candidates.insert(d2); isDivisor[d2] = true; }
            }
        }
        int noDivK = -1;
        for (int k = 2; k <= maxVal + 1; k++) {
            if (!isDivisor[k]) { noDivK = k; break; }
        }
        if (noDivK != -1) candidates.insert(noDivK);

        long long bestScore = LLONG_MIN;
        int bestK = -1;
        for (int k : candidates) {
            long long score = kadane(nums, k);
            if (score > bestScore || (score == bestScore && k < bestK)) {
                bestScore = score;
                bestK = k;
            }
        }

        long long result = ((bestScore % MOD) * (bestK % MOD)) % MOD;
        result = ((result % MOD) + MOD) % MOD;
        return (int)result;
    }
};
