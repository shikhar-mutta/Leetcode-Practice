// Link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int total = 0;
        for (int top = 0; top < rows; top++) {
            vector<int> colSum(cols, 0);
            for (int bottom = top; bottom < rows; bottom++) {
                for (int c = 0; c < cols; c++) colSum[c] += matrix[bottom][c];
                unordered_map<int,int> prefixCnt;
                prefixCnt[0] = 1;
                int sum = 0;
                for (int c = 0; c < cols; c++) {
                    sum += colSum[c];
                    total += prefixCnt[sum - target];
                    prefixCnt[sum]++;
                }
            }
        }
        return total;
    }
};
