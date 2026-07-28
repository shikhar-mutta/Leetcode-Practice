// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(1)
// Approach: Requires the WHOLE grid (both row and column) palindromic
// simultaneously, plus an even total 1-count. For each 4-way symmetric
// quadruple of cells, make all 4 equal at minimum cost (0 if already
// uniform, else flip the minority). Middle row/column (odd dimension) pairs
// are handled separately as 2-way symmetric pairs, tracking how many
// "both-1" pairs exist so an odd total can be fixed by flipping one such
// pair to both-0 (cost 2) if no cheaper single mismatch fix already
// happened; the true center cell (odd x odd) contributes its own value.
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int totalones = 0;
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int ones = 0;
                if (grid[i][j] == 1)
                    ones++;
                if (grid[n - i - 1][j] == 1)
                    ones++;
                if (grid[i][m - j - 1] == 1)
                    ones++;
                if (grid[n - i - 1][m - j - 1] == 1)
                    ones++;
                if (ones == 4 || ones == 0) {
                    continue;
                } else if (ones >= 2) {
                    ans += (4 - ones);
                } else
                    ans += ones;
            }
        }
        if ((n % 2 == 0) && (m % 2 == 0))
            return ans;
        int palinones = 0;
        int onechange = 0;
        if (n % 2 == 1) {
            int j = 0, k = m - 1;
            while (j < k) {
                if ((grid[n / 2][j] == 1) && (grid[n / 2][k] == 1))
                    palinones++;
                if (grid[n / 2][j] != grid[n / 2][k]) {
                    onechange++;
                    ans++;
                }
                j++;
                k--;
            }
        }
        if (m % 2 == 1) {
            int j = 0, k = n - 1;
            while (j < k) {
                if (grid[j][m / 2] == 1 && grid[k][m / 2] == 1)
                    palinones++;
                if (grid[j][m / 2] != grid[k][m / 2]) {
                    onechange++;
                    ans++;
                }
                j++;
                k--;
            }
        }
        if (palinones % 2 == 1) {
            if (onechange == 0)
                ans += 2;
        }
        if (n % 2 == 1 && m % 2 == 1 && grid[n / 2][m / 2] == 1)
            ans++;
        return ans;
    }
};
