// Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<bool> seenRow(n + 1, false), seenCol(n + 1, false);
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 1 || matrix[i][j] > n || seenRow[matrix[i][j]]) return false;
                seenRow[matrix[i][j]] = true;
                if (matrix[j][i] < 1 || matrix[j][i] > n || seenCol[matrix[j][i]]) return false;
                seenCol[matrix[j][i]] = true;
            }
        }
        return true;
    }
};
