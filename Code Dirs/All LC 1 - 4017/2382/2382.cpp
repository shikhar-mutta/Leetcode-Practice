// Link: https://leetcode.com/problems/maximum-segment-sum-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        vector<long long> sum(n, 0);
        vector<bool> active(n, false);

        int m = removeQueries.size();
        vector<long long> res(m);
        res[m - 1] = 0;
        long long curMax = 0;
        for (int q = m - 2; q >= 0; q--) {
            int idx = removeQueries[q + 1];
            active[idx] = true;
            sum[idx] = nums[idx];
            if (idx > 0 && active[idx - 1]) {
                int r1 = find(idx), r2 = find(idx - 1);
                if (r1 != r2) { sum[r2] += sum[r1]; parent[r1] = r2; }
            }
            if (idx < n - 1 && active[idx + 1]) {
                int r1 = find(idx), r2 = find(idx + 1);
                if (r1 != r2) { sum[r2] += sum[r1]; parent[r1] = r2; }
            }
            curMax = max(curMax, sum[find(idx)]);
            res[q] = curMax;
        }
        return res;
    }
};
