// Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveRun(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int best = 1, cur = 1;
        for (int i = 1; i < (int)bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) cur++;
            else cur = 1;
            best = max(best, cur);
        }
        return best;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hGap = maxConsecutiveRun(hBars) + 1;
        int vGap = maxConsecutiveRun(vBars) + 1;
        int side = min(hGap, vGap);
        return side * side;
    }
};
