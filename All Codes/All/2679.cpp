// Link: https://leetcode.com/problems/sum-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto &row : nums) sort(row.begin(), row.end());
        int m = nums.size(), n = nums[0].size();
        int total = 0;
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) mx = max(mx, nums[i][j]);
            total += mx;
        }
        return total;
    }
};
