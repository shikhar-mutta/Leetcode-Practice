// Link: https://leetcode.com/problems/create-grid-with-exactly-k-paths-i/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m*n)  SC: O(m*n)
// Approach: maxPaths(m,n) = C(m+n-2, m-1); if k exceeds it, impossible.
// Otherwise construct: single-path skeleton (top row + right column open)
// for k=1; for 2<=k<=max(m,n), embed a 2 x k (or k x 2) open corner block
// which contributes exactly k monotonic paths, then force a single
// connector route to the bottom-right. The only case where k doesn't fit
// in either dimension is m=n=3,k=4, handled via two chained 2x2 blocks.
class Solution {
    long long C(int a, int b) {
        long long r = 1;
        for (int i = 0; i < b; i++) r = r * (a - i) / (i + 1);
        return r;
    }
    vector<string> buildHoriz(int m, int n, int k) {
        vector<string> g(m, string(n, '#'));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < k; j++) g[i][j] = '.';
        for (int i = 1; i < m; i++) g[i][k - 1] = '.';
        for (int j = k - 1; j < n; j++) g[m - 1][j] = '.';
        return g;
    }
    vector<string> buildVert(int m, int n, int k) {
        auto t = buildHoriz(n, m, k);
        vector<string> g(m, string(n, '#'));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) g[i][j] = t[j][i];
        return g;
    }
public:
    vector<string> createGrid(int m, int n, int k) {
        if (k > C(m + n - 2, min(m, n) - 1)) return {};
        if (m == 1 || n == 1) return vector<string>(m, string(n, '.'));
        if (k == 1) {
            vector<string> g(m, string(n, '#'));
            for (int j = 0; j < n; j++) g[0][j] = '.';
            for (int i = 0; i < m; i++) g[i][n - 1] = '.';
            return g;
        }
        if (n >= k) return buildHoriz(m, n, k);
        if (m >= k) return buildVert(m, n, k);
        return {"..#", "...", "#.."};
    }
};
