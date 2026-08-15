// Link: https://leetcode.com/problems/find-minimum-log-transportation-cost/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: given n,m <= 2k, at most one log can exceed the truck limit
// k. If neither does, no cut is needed. Otherwise cut the longer log x
// into pieces k and (x-k) — one piece exactly fits a truck, the other
// (x-k <= k since x <= 2k) fits another — at cost k*(x-k).
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long x = max(n, m);
        if (x <= k) return 0;
        return k * (x - k);
    }
};
