// Link: https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 + a*n^2) worst case (n*n grid marking + per-artifact rectangle
//     scan; a = artifacts.size())
// SC: O(n^2)
// Approach: mark every dug cell in an n x n grid, then for each artifact's
// bounding rectangle check whether every cell inside it has been dug;
// count the artifacts where that holds fully.
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts,
                     vector<vector<int>>& dig) {
        vector<vector<bool>> grid(n, vector<bool>(n, false));

        for (auto& point : dig) {
            int x = point[0];
            int y = point[1];
            grid[x][y] = true;
        }

        int count = 0;
        int size = artifacts.size();
        for (int i = 0; i < size; i++) {
            int r1 = artifacts[i][0];
            int c1 = artifacts[i][1];
            int r2 = artifacts[i][2];
            int c2 = artifacts[i][3];

            bool flag = true;

            for (int row = r1; row <= r2; row++) {
                for (int col = c1; col <= c2; col++) {
                    if (!grid[row][col]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                count++;
            }
        }

        return count;
    }
};
