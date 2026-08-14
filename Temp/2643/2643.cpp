// Link: https://leetcode.com/problems/row-with-maximum-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int bestRow = 0, bestCount = -1;
        for (int i = 0; i < (int)mat.size(); i++) {
            int count = 0;
            for (int x : mat[i]) if (x == 1) count++;
            if (count > bestCount) { bestCount = count; bestRow = i; }
        }
        return {bestRow, bestCount};
    }
};
