// Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int,int>> pos;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pos[mat[i][j]] = {i, j};

        vector<int> rowCount(m, 0), colCount(n, 0);
        for (int k = 0; k < (int)arr.size(); k++) {
            auto [r, c] = pos[arr[k]];
            rowCount[r]++;
            colCount[c]++;
            if (rowCount[r] == n || colCount[c] == m) return k;
        }
        return -1;
    }
};
