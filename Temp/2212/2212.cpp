// Link: https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int bestScore = 0;
        int bestMask = 0;
        for (int mask = 0; mask < (1 << 12); mask++) {
            int arrowsUsed = 0, score = 0;
            for (int i = 0; i < 12; i++) {
                if (mask & (1 << i)) {
                    arrowsUsed += aliceArrows[i] + 1;
                    score += i;
                }
            }
            if (arrowsUsed <= numArrows && score > bestScore) {
                bestScore = score;
                bestMask = mask;
            }
        }
        vector<int> res(12, 0);
        int used = 0;
        for (int i = 0; i < 12; i++) {
            if (bestMask & (1 << i)) {
                res[i] = aliceArrows[i] + 1;
                used += res[i];
            }
        }
        res[0] += (numArrows - used);
        return res;
    }
};
