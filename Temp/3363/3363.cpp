// Link: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        const long long NEG = LLONG_MIN / 2;

        long long diagSum = 0;
        for (int k = 0; k < n - 1; k++) diagSum += fruits[k][k];

        // child2: starts (0, n-1), stays in region j > i
        vector<vector<long long>> dp2(n, vector<long long>(n, NEG));
        dp2[0][n-1] = fruits[0][n-1];
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j < n; j++) {
                long long best = NEG;
                for (int dj : {-1, 0, 1}) {
                    int pj = j + dj;
                    if (pj > i - 1 && pj >= 0 && pj < n) {
                        best = max(best, dp2[i-1][pj]);
                    }
                }
                if (best > NEG / 2) dp2[i][j] = best + fruits[i][j];
            }
        }
        long long answer2 = (n >= 2) ? dp2[n-2][n-1] : 0;

        // child3: starts (n-1, 0), stays in region i > j
        vector<vector<long long>> dp3(n, vector<long long>(n, NEG));
        dp3[n-1][0] = fruits[n-1][0];
        for (int j = 1; j <= n - 2; j++) {
            for (int i = j + 1; i < n; i++) {
                long long best = NEG;
                for (int di : {-1, 0, 1}) {
                    int pi = i + di;
                    if (pi > j - 1 && pi >= 0 && pi < n) {
                        best = max(best, dp3[pi][j-1]);
                    }
                }
                if (best > NEG / 2) dp3[i][j] = best + fruits[i][j];
            }
        }
        long long answer3 = (n >= 2) ? dp3[n-1][n-2] : 0;

        long long total = diagSum + fruits[n-1][n-1] + answer2 + answer3;
        return (int)total;
    }
};
