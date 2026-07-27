// Link: https://leetcode.com/problems/zero-array-transformation-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n + q) * log q) SC: O(n)
// Approach: feasibility of "array can be zeroed using first k queries" is
// monotonic in k (more queries only help), so binary search the minimum k.
// For a fixed k, build a difference array from queries[0..k) (each query
// adds up to val at every covered index) and check the resulting coverage
// at every index is >= nums[index].
class Solution {
    bool feasible(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }
        long long cover = 0;
        for (int i = 0; i < n; i++) {
            cover += diff[i];
            if (cover < nums[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int lo = 0, hi = queries.size();
        if (!feasible(nums, queries, hi)) return -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (feasible(nums, queries, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
