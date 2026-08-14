// Link: https://leetcode.com/problems/maximum-rows-covered-by-columns/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowMask(m, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j]) rowMask[i] |= (1 << j);

        int best = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != numSelect) continue;
            int covered = 0;
            for (int i = 0; i < m; i++)
                if ((rowMask[i] & mask) == rowMask[i]) covered++;
            best = max(best, covered);
        }
        return best;
    }
};
