// Link: https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: gardens already >= target are already "full" (never touch).
// Sort remaining ascending. Try making the top k of them full (largest k
// suffix, cost = sum(target - flowers[i]) for those), then with leftover
// budget, binary search the maximum achievable minimum height among the
// remaining n-k leftmost gardens (to maximize partial * minHeight), using
// prefix sums for O(1) cost-of-raising-to-h checks.
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        long long alreadyFullBonus = 0;
        vector<int> v;
        for (int f : flowers) {
            if (f >= target) alreadyFullBonus += full;
            else v.push_back(f);
        }
        sort(v.begin(), v.end());
        int m = v.size();
        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++) prefix[i+1] = prefix[i] + v[i];
        if (m == 0) return alreadyFullBonus;
        // suffix cost to make v[k..m-1] all == target
        vector<long long> suffixCost(m + 1, 0);
        for (int k = m - 1; k >= 0; k--) suffixCost[k] = suffixCost[k+1] + (target - v[k]);
        long long best = 0;
        for (int k = 0; k <= m; k++) {
            long long cost = suffixCost[k];
            if (cost > newFlowers) continue;
            long long remain = newFlowers - cost;
            long long bonusFull = (long long)(m - k) * full;
            // among v[0..k-1], maximize min height h using budget remain
            long long lo = 0, hi = target - 1, bestH = 0;
            if (k > 0) {
                while (lo <= hi) {
                    long long h = (lo + hi) / 2;
                    // cost to raise all first k to at least h
                    int idx = upper_bound(v.begin(), v.begin() + k, h) - v.begin();
                    long long costH = (long long)idx * h - prefix[idx] + 0; // those below h raised to h
                    // those already >= h among first k cost 0 extra
                    if (costH <= remain) { bestH = h; lo = h + 1; }
                    else hi = h - 1;
                }
            }
            long long total = alreadyFullBonus + bonusFull + (long long)bestH * partial;
            best = max(best, total);
        }
        return best;
    }
};
