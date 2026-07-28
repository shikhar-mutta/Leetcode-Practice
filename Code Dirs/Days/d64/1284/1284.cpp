// Link: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^(m*n) * m*n)  bounded since m*n<=15  SC: O(2^(m*n))
// Approach: encode the whole grid as a bitmask (m*n<=15 cells). BFS over
// mask states; from each mask, try flipping each cell (which XORs that
// cell and its 4 neighbors) to reach a new state, until the all-zero
// mask is found.
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j]) start |= (1 << (i * n + j));

        if (start == 0) return 0;

        vector<int> flipMask(m * n, 0);
        int dx[5] = {0,0,0,1,-1}, dy[5] = {0,1,-1,0,0};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int mask = 0;
                for (int d = 0; d < 5; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) mask |= (1 << (ni * n + nj));
                }
                flipMask[i * n + j] = mask;
            }

        unordered_set<int> visited;
        visited.insert(start);
        queue<int> q;
        q.push(start);
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                int cur = q.front(); q.pop();
                for (int cell = 0; cell < m * n; cell++) {
                    int next = cur ^ flipMask[cell];
                    if (next == 0) return steps;
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
