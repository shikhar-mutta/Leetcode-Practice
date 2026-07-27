// Link: https://leetcode.com/problems/find-maximum-value-in-a-constrained-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: compute the tightest achievable upper bound U[i] for each
// position via a forward pass (U[i] = min(restriction[i], U[i-1]+diff[i-1]),
// starting from U[0]=0) followed by a backward pass propagating bounds
// from restrictions on the right (U[i] = min(U[i], U[i+1]+diff[i])).
// The answer is the maximum U[i]; every U[i] is achievable since diff
// steps can always be reduced down to match a lower neighbor.
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<long long> U(n, LLONG_MAX);
        U[0] = 0;
        for (auto& r : restrictions) U[r[0]] = min(U[r[0]], (long long)r[1]);

        for (int i = 1; i < n; i++) U[i] = min(U[i], U[i-1] + diff[i-1]);
        for (int i = n - 2; i >= 0; i--) U[i] = min(U[i], U[i+1] + diff[i]);

        return *max_element(U.begin(), U.end());
    }
};
