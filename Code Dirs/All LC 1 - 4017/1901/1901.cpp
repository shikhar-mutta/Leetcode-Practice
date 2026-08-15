// Link: https://leetcode.com/problems/find-a-peak-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int lo = 0, hi = cols - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int maxRow = 0;
            for (int i = 0; i < rows; i++) if (mat[i][mid] > mat[maxRow][mid]) maxRow = i;
            if (mat[maxRow][mid] < mat[maxRow][mid + 1]) lo = mid + 1;
            else hi = mid;
        }
        int maxRow = 0;
        for (int i = 0; i < rows; i++) if (mat[i][lo] > mat[maxRow][lo]) maxRow = i;
        return {maxRow, lo};
    }
};
