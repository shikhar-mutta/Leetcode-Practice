// Link: https://leetcode.com/problems/distinct-points-reachable-after-substring-removal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: since final position is just the sum of all move vectors,
// removing a contiguous window's moves simply subtracts that window's
// own net displacement from the total (order doesn't matter for a sum).
// Compute prefix sums, then for each window of length k, final position
// = total - (prefix[i+k] - prefix[i]); collect distinct results.
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<pair<int,int>> prefix(n + 1, {0, 0});
        for (int i = 0; i < n; i++) {
            int dx = 0, dy = 0;
            if (s[i] == 'U') dy = 1;
            else if (s[i] == 'D') dy = -1;
            else if (s[i] == 'L') dx = -1;
            else dx = 1;
            prefix[i+1] = {prefix[i].first + dx, prefix[i].second + dy};
        }
        auto total = prefix[n];
        set<pair<int,int>> distinct;
        for (int i = 0; i + k <= n; i++) {
            int rx = prefix[i+k].first - prefix[i].first;
            int ry = prefix[i+k].second - prefix[i].second;
            distinct.insert({total.first - rx, total.second - ry});
        }
        return distinct.size();
    }
};
