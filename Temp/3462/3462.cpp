// Link: https://leetcode.com/problems/maximum-sum-with-at-most-k-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> candidates;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> row = grid[i];
            sort(row.rbegin(), row.rend());
            int lim = min((int)row.size(), limits[i]);
            for (int j = 0; j < lim; j++) candidates.push_back(row[j]);
        }
        sort(candidates.rbegin(), candidates.rend());
        long long sum = 0;
        int take = min((int)candidates.size(), k);
        for (int i = 0; i < take; i++) sum += candidates[i];
        return sum;
    }
};
