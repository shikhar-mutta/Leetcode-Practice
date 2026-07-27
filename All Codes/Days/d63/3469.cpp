// Link: https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: memoized recursion on (prev, k) = one surviving "held"
// element at index prev, plus the next untouched suffix starting at k.
// The active triple is (prev, nums[k], nums[k+1]); try removing each of
// the 3 possible pairs (paying the max of the pair) and keep the third
// as the new held element, recursing on the remaining suffix. Base cases
// handle 0/1/2 elements left.
class Solution {
    vector<vector<int>> memo;
    vector<int>* nums;
    int n;
    int solve(int prev, int k) {
        if (k >= n) return (*nums)[prev];
        if (k == n - 1) return max((*nums)[prev], (*nums)[k]);
        if (memo[prev][k] != -1) return memo[prev][k];

        int a = (*nums)[prev], b = (*nums)[k], c = (*nums)[k+1];
        int opt1 = max(a, b) + solve(k+1, k+2);
        int opt2 = max(a, c) + solve(k, k+2);
        int opt3 = max(b, c) + solve(prev, k+2);
        return memo[prev][k] = min({opt1, opt2, opt3});
    }
public:
    int minCost(vector<int>& in) {
        n = in.size();
        nums = &in;
        if (n == 1) return in[0];
        if (n == 2) return max(in[0], in[1]);
        memo.assign(n, vector<int>(n, -1));
        return solve(0, 1);
    }
};
