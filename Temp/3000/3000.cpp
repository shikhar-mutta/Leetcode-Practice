// Link: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestDiag = -1;
        int bestArea = 0;
        for (auto& d : dimensions) {
            long long diag = (long long)d[0]*d[0] + (long long)d[1]*d[1];
            int area = d[0]*d[1];
            if (diag > bestDiag || (diag == bestDiag && area > bestArea)) {
                bestDiag = diag;
                bestArea = area;
            }
        }
        return bestArea;
    }
};
