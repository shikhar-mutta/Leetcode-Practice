// Link: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m, best;

    void dfs(vector<int>& height, int cnt) {
        if (cnt >= best) return;
        int pos = -1, low = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (height[i] < low) { low = height[i]; pos = i; }
        }
        if (low == n) { best = min(best, cnt); return; }

        int maxSize = 0;
        for (int i = pos; i < m; i++) {
            if (height[i] != low) break;
            maxSize++;
        }
        maxSize = min(maxSize, n - low);

        for (int size = maxSize; size >= 1; size--) {
            for (int i = pos; i < pos + size; i++) height[i] += size;
            dfs(height, cnt + 1);
            for (int i = pos; i < pos + size; i++) height[i] -= size;
        }
    }

    int tilingRectangle(int n, int m) {
        this->n = n; this->m = m;
        best = n * m;
        vector<int> height(m, 0);
        dfs(height, 0);
        return best;
    }
};
