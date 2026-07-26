// Link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n)
// SC: O(1)
// Approach: brute force every possible hourglass by its top-left corner
// (i, j), summing the top row of 3, the middle single cell, and the
// bottom row of 3, tracking the running maximum.
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int max = INT_MIN;
        for(int i = 0; i < grid.size()-2; i++) {
            for(int j = 0; j < grid[i].size()-2; j++) {
                int sum = 0;
                sum += grid[i][j] + grid[i][j+1] + grid[i][j+2];
                sum += grid[i+1][j+1];
                sum += grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

                if(sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }
};
