// Link: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> prefix;

    int rectSum(int r1, int r2, int c1, int c2) {
        if (r1 > r2 || c1 > c2) return 0;
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    }

    int bboxArea(int r1, int r2, int c1, int c2) {
        if (r1 > r2 || c1 > c2) return 0;
        if (rectSum(r1, r2, c1, c2) == 0) return 0;
        int minR = r1, maxR = r2, minC = c1, maxC = c2;
        while (minR <= maxR && rectSum(minR, minR, c1, c2) == 0) minR++;
        while (maxR >= minR && rectSum(maxR, maxR, c1, c2) == 0) maxR--;
        while (minC <= maxC && rectSum(r1, r2, minC, minC) == 0) minC++;
        while (maxC >= minC && rectSum(r1, r2, maxC, maxC) == 0) maxC--;
        return (maxR - minR + 1) * (maxC - minC + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        prefix.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];

        int best = INT_MAX;

        // Strategy A: 3 horizontal bands
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
                best = min(best, bboxArea(0,i,0,m-1) + bboxArea(i+1,j,0,m-1) + bboxArea(j+1,n-1,0,m-1));

        // Strategy B: 3 vertical bands
        for (int i = 0; i < m - 2; i++)
            for (int j = i + 1; j < m - 1; j++)
                best = min(best, bboxArea(0,n-1,0,i) + bboxArea(0,n-1,i+1,j) + bboxArea(0,n-1,j+1,m-1));

        // Strategy C: horizontal split, then split TOP by columns
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m - 1; j++)
                best = min(best, bboxArea(0,i,0,j) + bboxArea(0,i,j+1,m-1) + bboxArea(i+1,n-1,0,m-1));

        // Strategy D: horizontal split, then split BOTTOM by columns
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m - 1; j++)
                best = min(best, bboxArea(0,i,0,m-1) + bboxArea(i+1,n-1,0,j) + bboxArea(i+1,n-1,j+1,m-1));

        // Strategy E: vertical split, then split LEFT by rows
        for (int i = 0; i < m - 1; i++)
            for (int j = 0; j < n - 1; j++)
                best = min(best, bboxArea(0,j,0,i) + bboxArea(j+1,n-1,0,i) + bboxArea(0,n-1,i+1,m-1));

        // Strategy F: vertical split, then split RIGHT by rows
        for (int i = 0; i < m - 1; i++)
            for (int j = 0; j < n - 1; j++)
                best = min(best, bboxArea(0,n-1,0,i) + bboxArea(0,j,i+1,m-1) + bboxArea(j+1,n-1,i+1,m-1));

        return best;
    }
};
