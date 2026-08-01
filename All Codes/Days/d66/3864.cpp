// Link: https://leetcode.com/problems/minimum-cost-to-partition-a-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: a segment [l,r) costs (r-l)*X*encCost if it has X>0 sensitive
// ('1') chars, or flatCost if X==0. If the segment's length is even, it can
// instead be split at its exact midpoint into two independently-optimal
// halves, whichever is cheaper. Since the split is always at the fixed
// midpoint (a segment-tree-like recursive structure, not an arbitrary
// partition), recurse from the full range using digit-count prefix sums to
// get each segment's sensitive-char count in O(1).
class Solution {
    vector<int> pre;
    int encCost, flatCost;
    long long dfs(int l, int r) {
        int x = pre[r] - pre[l];
        long long res = x ? (long long)(r - l) * x * encCost : flatCost;
        if ((r - l) % 2 == 0) {
            int mid = (l + r) / 2;
            res = min(res, dfs(l, mid) + dfs(mid, r));
        }
        return res;
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        pre.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + (s[i-1] - '0');
        this->encCost = encCost;
        this->flatCost = flatCost;
        return dfs(0, n);
    }
};
