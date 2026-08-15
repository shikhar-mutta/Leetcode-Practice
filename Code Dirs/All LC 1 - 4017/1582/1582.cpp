// Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> rowSum(rows, 0), colSum(cols, 0);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (mat[i][j] == 1) { rowSum[i]++; colSum[j]++; }

        int count = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) count++;
        return count;
    }
};
