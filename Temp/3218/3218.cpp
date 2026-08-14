// Link: https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        int hi = 0, vi = 0;
        long long horizPieces = 1, vertPieces = 1;
        long long cost = 0;
        while (hi < (int)horizontalCut.size() || vi < (int)verticalCut.size()) {
            bool takeH = (vi >= (int)verticalCut.size()) ||
                         (hi < (int)horizontalCut.size() && horizontalCut[hi] >= verticalCut[vi]);
            if (takeH) {
                cost += (long long)horizontalCut[hi] * vertPieces;
                horizPieces++;
                hi++;
            } else {
                cost += (long long)verticalCut[vi] * horizPieces;
                vertPieces++;
                vi++;
            }
        }
        return (int)cost;
    }
};
