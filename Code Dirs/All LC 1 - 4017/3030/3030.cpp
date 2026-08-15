// Link: https://leetcode.com/problems/find-the-grid-of-region-average/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<long long>> sumAcc(n, vector<long long>(m, 0));
        vector<vector<int>> cntAcc(n, vector<int>(m, 0));

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                bool valid = true;
                for (int r = 0; r < 3 && valid; r++) {
                    for (int c = 0; c < 3 && valid; c++) {
                        int v = image[i+r][j+c];
                        if (c+1 < 3 && abs(v - image[i+r][j+c+1]) > threshold) valid = false;
                        if (r+1 < 3 && abs(v - image[i+r+1][j+c]) > threshold) valid = false;
                    }
                }
                if (!valid) continue;
                long long sum = 0;
                for (int r = 0; r < 3; r++)
                    for (int c = 0; c < 3; c++)
                        sum += image[i+r][j+c];
                int avg = (int)(sum / 9);
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        sumAcc[i+r][j+c] += avg;
                        cntAcc[i+r][j+c]++;
                    }
                }
            }
        }

        vector<vector<int>> res = image;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cntAcc[i][j] > 0) res[i][j] = (int)(sumAcc[i][j] / cntAcc[i][j]);
        return res;
    }
};
