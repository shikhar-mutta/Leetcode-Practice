// Link: https://leetcode.com/problems/maximum-segment-sum-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N alpha(N)), SC: O(N)
// Approach: process queries in reverse (build-up instead of tear-down), DSU union with active
// left/right neighbors, track running max segment sum.
class Solution {
public:
    vector<int> parent;
    vector<long long> segSum;

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        parent[a] = b;
        segSum[b] += segSum[a];
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        segSum.assign(n, 0);
        vector<int> active(n, 0);

        int q = removeQueries.size();
        vector<long long> revAns(q);
        long long curMax = 0;

        for (int i = q - 1; i >= 0; i--) {
            revAns[i] = curMax;
            int idx = removeQueries[i];
            active[idx] = 1;
            segSum[idx] = nums[idx];
            if (idx > 0 && active[idx-1]) unite(idx, idx-1);
            if (idx < n-1 && active[idx+1]) unite(idx, idx+1);
            curMax = max(curMax, segSum[find(idx)]);
        }

        return revAns;
    }
};
