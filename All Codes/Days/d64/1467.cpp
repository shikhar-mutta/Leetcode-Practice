// Link: https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<double> fact;
    int k, total;
    double validWays = 0, totalWays = 0;

    void dfs(int idx, vector<int>& balls, int aCount, int bCount, int aColors, int bColors, double aWays, double bWays) {
        if (idx == (int)balls.size()) {
            if (aCount != total - aCount) return;
            totalWays += aWays * bWays;
            if (aCount == bCount && aColors == bColors)
                validWays += aWays * bWays;
            return;
        }
        for (int x = 0; x <= balls[idx]; x++) {
            int y = balls[idx] - x;
            double waysA = aWays / (fact[x] * fact[y]) * fact[balls[idx]];
            dfs(idx + 1, balls, aCount + x, bCount + y,
                aColors + (x > 0 ? 1 : 0), bColors + (y > 0 ? 1 : 0),
                waysA, bWays);
        }
    }
public:
    double getProbability(vector<int>& balls) {
        k = balls.size();
        total = accumulate(balls.begin(), balls.end(), 0);
        fact.assign(total + 1, 1.0);
        for (int i = 1; i <= total; i++) fact[i] = fact[i-1] * i;
        dfs(0, balls, 0, 0, 0, 0, 1.0, 1.0);
        return validWays / totalWays;
    }
};
