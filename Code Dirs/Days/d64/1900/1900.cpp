// Link: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^3) states * O(n) classification  SC: O(n^3)
// Approach: memoized recursion on (n,a,b), a<b. If a+b==n+1 they meet now.
// If a+b>n+1, mirror (relabel k -> n+1-k) to the symmetric case, same round.
// Otherwise fixed pairing (k, n+1-k) determines partners; every non-a/b match
// winner is free EXCEPT pairs entirely inside the same region (before/between/
// after a,b), whose contribution is deterministic. Classify every position's
// pairing to get deterministic between-survivors plus the free before<->after
// and between<->after cross-pair counts, then enumerate the achievable new
// ranks (i,j) for a,b within those bounds.
class Solution {
    map<tuple<int,int,int>, pair<int,int>> memo;

    int region(int k, int a, int b) {
        if (k < a) return 0;
        if (k > a && k < b) return 1;
        return 2; // k > b
    }

    pair<int,int> solve(int n, int a, int b) {
        if (a > b) swap(a, b);
        if (a + b == n + 1) return {1, 1};
        if (a + b > n + 1) return solve(n, n + 1 - b, n + 1 - a);
        auto key = make_tuple(n, a, b);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        vector<bool> visited(n + 1, false);
        visited[a] = visited[b] = true;
        int detBetween = 0, freeBeforeAfter = 0, freeBetweenAfter = 0;
        for (int k = 1; k <= n; k++) {
            if (visited[k]) continue;
            int m = n + 1 - k;
            if (m == k) {
                visited[k] = true;
                if (region(k, a, b) == 1) detBetween++;
                continue;
            }
            visited[k] = visited[m] = true;
            int rk = region(k, a, b), rm = region(m, a, b);
            if (rk == rm) {
                if (rk == 1) detBetween++;
                // region 2 == region 2 is deterministic "after" survivor, doesn't affect i/j
            } else if ((rk == 0 && rm == 2) || (rk == 2 && rm == 0)) {
                freeBeforeAfter++;
            } else if ((rk == 1 && rm == 2) || (rk == 2 && rm == 1)) {
                freeBetweenAfter++;
            }
        }

        int newN = (n + 1) / 2;
        int mn = INT_MAX, mx = INT_MIN;
        for (int beforeSurv = 0; beforeSurv <= freeBeforeAfter; beforeSurv++) {
            int i = beforeSurv + 1;
            for (int betweenSurv = detBetween; betweenSurv <= detBetween + freeBetweenAfter; betweenSurv++) {
                int j = i + betweenSurv + 1;
                if (j > newN) continue; // guard against over-counted cross-pair combos
                auto [e, l] = solve(newN, i, j);
                mn = min(mn, e + 1);
                mx = max(mx, l + 1);
            }
        }
        memo[key] = {mn, mx};
        return {mn, mx};
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto res = solve(n, firstPlayer, secondPlayer);
        return {res.first, res.second};
    }
};
