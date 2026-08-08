// Link: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j]) start |= (1 << (i * n + j));

        if (start == 0) return 0;

        int dr[] = {0,0,0,1,-1}, dc[] = {0,1,-1,0,0};
        unordered_set<int> visited;
        visited.insert(start);
        queue<int> q;
        q.push(start);
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            for (int k = 0; k < sz; k++) {
                int state = q.front(); q.pop();
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int next = state;
                        for (int d = 0; d < 5; d++) {
                            int ni = i + dr[d], nj = j + dc[d];
                            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                            next ^= (1 << (ni * n + nj));
                        }
                        if (next == 0) return dist;
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
