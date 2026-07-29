// Link: https://leetcode.com/problems/equal-sum-grid-partition-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exists(int a, int b, int n, function<int(int,int)> at, long long v, unordered_map<long long,int>& counts) {
        if (v < 0) return false;
        if (b - a + 1 == 1) {
            return at(a, 0) == v || at(a, n - 1) == v;
        } else if (n == 1) {
            return at(a, 0) == v || at(b, 0) == v;
        } else {
            auto it = counts.find(v);
            return it != counts.end() && it->second > 0;
        }
    }

    bool checkDirection(int m, int n, function<int(int,int)> at, function<long long(int)> lineSum, long long total) {
        // "lines" are rows for horizontal (m of them, dims n each), cuts at i=0..m-2
        unordered_map<long long,int> topCounts, botCounts;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) botCounts[at(i, j)]++;
        }
        long long topSum = 0;
        for (int i = 0; i <= m - 2; i++) {
            for (int j = 0; j < n; j++) {
                long long val = at(i, j);
                botCounts[val]--;
                topCounts[val]++;
            }
            topSum += lineSum(i);
            long long botSum = total - topSum;
            long long diff = topSum - botSum;
            if (diff == 0) return true;
            long long v = llabs(diff);
            if (diff > 0) {
                // remove from top: rows 0..i
                if (exists(0, i, n, at, v, topCounts)) return true;
            } else {
                // remove from bottom: rows i+1..m-1
                if (exists(i + 1, m - 1, n, at, v, botCounts)) return true;
            }
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (auto& row : grid) for (int x : row) total += x;

        auto atRC = [&](int r, int c) { return grid[r][c]; };
        auto rowSum = [&](int r) {
            long long s = 0;
            for (int c = 0; c < n; c++) s += grid[r][c];
            return s;
        };
        if (m >= 2 && checkDirection(m, n, atRC, rowSum, total)) return true;

        auto atCR = [&](int c, int r) { return grid[r][c]; }; // "a"=col index, "b"=row index within col-major view
        auto colSum = [&](int c) {
            long long s = 0;
            for (int r = 0; r < m; r++) s += grid[r][c];
            return s;
        };
        if (n >= 2 && checkDirection(n, m, atCR, colSum, total)) return true;

        return false;
    }
};
