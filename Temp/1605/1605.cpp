// Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = min(rowSum[i], colSum[j]);
                res[i][j] = val;
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        return res;
    }
};
