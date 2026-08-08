// Link: https://leetcode.com/problems/regions-cut-by-slashes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> parent(4 * n * n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        // 0=top,1=right,2=bottom,3=left triangles per cell
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int base = 4 * (r * n + c);
                char ch = grid[r][c];
                if (ch == '/') {
                    unite(base + 0, base + 3);
                    unite(base + 1, base + 2);
                } else if (ch == '\\') {
                    unite(base + 0, base + 1);
                    unite(base + 2, base + 3);
                } else {
                    unite(base + 0, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                }
                if (r + 1 < n) unite(base + 2, 4 * ((r+1) * n + c) + 0);
                if (c + 1 < n) unite(base + 1, 4 * (r * n + c + 1) + 3);
            }
        }

        unordered_set<int> roots;
        for (int i = 0; i < 4 * n * n; i++) roots.insert(find(i));
        return roots.size();
    }
};
