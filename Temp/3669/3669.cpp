// Link: https://leetcode.com/problems/balanced-k-factor-decomposition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(divisor-tree size) SC: O(k)
// Approach: backtracking search choosing k divisors in non-decreasing
// order whose product is n (pruned so the smallest remaining factor
// can't exceed remaining^(1/countLeft), keeping the tree small), tracking
// the combination with the smallest max-min spread.
class Solution {
    vector<int> best;
    int bestSpread = INT_MAX;
    vector<int> path;

    void dfs(int start, long long remaining, int countLeft) {
        if (countLeft == 1) {
            if (remaining >= start) {
                path.push_back((int)remaining);
                int mx = *max_element(path.begin(), path.end());
                int mn = *min_element(path.begin(), path.end());
                if (mx - mn < bestSpread) { bestSpread = mx - mn; best = path; }
                path.pop_back();
            }
            return;
        }
        for (long long d = start; ; d++) {
            long long p = 1;
            bool overflow = false;
            for (int i = 0; i < countLeft; i++) { p *= d; if (p > remaining) { overflow = true; break; } }
            if (overflow) break;
            if (remaining % d == 0) {
                path.push_back((int)d);
                dfs((int)d, remaining / d, countLeft - 1);
                path.pop_back();
            }
        }
    }
public:
    vector<int> minDifference(int n, int k) {
        dfs(1, n, k);
        return best;
    }
};
