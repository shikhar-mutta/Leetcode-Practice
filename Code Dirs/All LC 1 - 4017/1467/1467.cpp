// Link: https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<double>> binom;

    void buildBinom(int maxN) {
        binom.assign(maxN + 1, vector<double>(maxN + 1, 0));
        for (int i = 0; i <= maxN; i++) {
            binom[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                binom[i][j] = binom[i-1][j-1] + (j <= i - 1 ? binom[i-1][j] : 0);
            }
        }
    }

    double validWays = 0;
    int half;

    void dfs(int idx, vector<int>& balls, int colors1, int colors2, int balls1, int balls2, double ways) {
        if (idx == (int)balls.size()) {
            if (balls1 == half && colors1 == colors2) validWays += ways;
            return;
        }
        for (int x = 0; x <= balls[idx]; x++) {
            int y = balls[idx] - x;
            int nc1 = colors1 + (x > 0 ? 1 : 0);
            int nc2 = colors2 + (y > 0 ? 1 : 0);
            dfs(idx + 1, balls, nc1, nc2, balls1 + x, balls2 + y, ways * binom[balls[idx]][x]);
        }
    }

    double getProbability(vector<int>& balls) {
        int total = 0;
        for (int b : balls) total += b;
        half = total / 2;
        buildBinom(total);

        validWays = 0;
        dfs(0, balls, 0, 0, 0, 0, 1.0);

        double denom = binom[total][half];
        return validWays / denom;
    }
};
