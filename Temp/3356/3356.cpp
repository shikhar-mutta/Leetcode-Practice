// Link: https://leetcode.com/problems/zero-array-transformation-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool feasible(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        if (feasible(nums, queries, 0)) return 0;
        if (!feasible(nums, queries, q)) return -1;

        int lo = 1, hi = q;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(nums, queries, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
