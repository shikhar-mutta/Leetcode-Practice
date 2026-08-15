// Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if ((int)original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < (int)original.size(); i++) res[i / n][i % n] = original[i];
        return res;
    }
};
