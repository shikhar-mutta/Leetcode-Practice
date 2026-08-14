// Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vals;
        for (auto& row : grid) for (int v : row) vals.push_back(v);
        int rem = vals[0] % x;
        for (int v : vals) if (v % x != rem) return -1;
        sort(vals.begin(), vals.end());
        int median = vals[vals.size() / 2];
        long long ops = 0;
        for (int v : vals) ops += abs(v - median) / x;
        return (int)ops;
    }
};
