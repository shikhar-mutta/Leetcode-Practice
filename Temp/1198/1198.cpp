// Link: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size();
        vector<int> cnt(10001, 0);
        for (auto& row : mat)
            for (int x : row)
                cnt[x]++;
        for (int v = 1; v <= 10000; v++)
            if (cnt[v] == rows) return v;
        return -1;
    }
};
