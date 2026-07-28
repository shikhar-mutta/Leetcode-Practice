// Link: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: exponential, bounded by n,m<=13 with heavy pruning  SC: O(n*m)
// Approach: backtracking over a "skyline" heightmap of the n x m
// rectangle. Always fill the lowest, then leftmost, uncompleted column
// first; try every square size (largest first) that fits without
// exceeding neighboring heights, place it, recurse, and prune whenever
// the current square count already reaches the best found so far.
class Solution {
    int n, m, best;
    vector<int> heights;
    void backtrack(int count) {
        if (count >= best) return;
        int minH = *min_element(heights.begin(), heights.end());
        if (minH == n) { best = count; return; }

        int col = 0;
        while (heights[col] != minH) col++;
        int maxSize = 0;
        while (col + maxSize < m && heights[col + maxSize] == minH) maxSize++;
        maxSize = min(maxSize, n - minH);

        for (int size = maxSize; size >= 1; size--) {
            for (int c = col; c < col + size; c++) heights[c] += size;
            backtrack(count + 1);
            for (int c = col; c < col + size; c++) heights[c] -= size;
        }
    }
public:
    int tilingRectangle(int n, int m) {
        this->n = n; this->m = m;
        heights.assign(m, 0);
        best = n * m;
        backtrack(0);
        return best;
    }
};
