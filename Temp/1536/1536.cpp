// Link: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            trailingZeros[i] = count;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int row = -1;
            for (int j = i; j < n; j++) {
                if (trailingZeros[j] >= need) { row = j; break; }
            }
            if (row == -1) return -1;
            while (row > i) {
                swap(trailingZeros[row], trailingZeros[row-1]);
                row--;
                swaps++;
            }
        }
        return swaps;
    }
};
