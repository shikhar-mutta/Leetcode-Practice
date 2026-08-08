// Link: https://leetcode.com/problems/maximum-matrix-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;
        for (auto& row : matrix) {
            for (int x : row) {
                sum += abs(x);
                if (x < 0) negCount++;
                minAbs = min(minAbs, abs(x));
            }
        }
        if (negCount % 2 == 0) return sum;
        return sum - 2LL * minAbs;
    }
};
