// Link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(rows^2 * cols)  SC: O(cols)
// Approach: for every pair of top/bottom rows, compress the matrix
// between them into a 1D array of column sums, then count subarrays of
// that array summing to target via the classic prefix-sum + hashmap
// technique (O(cols) per row-pair).
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int total = 0;
        for (int top = 0; top < m; top++) {
            vector<int> colSum(n, 0);
            for (int bottom = top; bottom < m; bottom++) {
                for (int c = 0; c < n; c++) colSum[c] += matrix[bottom][c];

                unordered_map<int,int> prefixCount;
                prefixCount[0] = 1;
                int prefix = 0;
                for (int c = 0; c < n; c++) {
                    prefix += colSum[c];
                    int need = prefix - target;
                    if (prefixCount.count(need)) total += prefixCount[need];
                    prefixCount[prefix]++;
                }
            }
        }
        return total;
    }
};
