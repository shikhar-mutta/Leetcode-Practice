// Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
                if (prefix[i+1][j+1] <= k) cnt++;
            }
        }
        return cnt;
    }
};
