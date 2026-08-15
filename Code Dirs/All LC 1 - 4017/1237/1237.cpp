// Link: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/

#include <bits/stdc++.h>
using namespace std;

class CustomFunction {
public:
    int fid = 1;
    int f(int x, int y) {
        return fid == 1 ? x + y : x * y;
    }
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int x = 1, y = 1000;
        while (x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y);
            if (val == z) {
                res.push_back({x, y});
                x++; y--;
            } else if (val < z) {
                x++;
            } else {
                y--;
            }
        }
        return res;
    }
};
