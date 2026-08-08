// Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const long long MOD = 1e9 + 7;
        int rows = pizza.size(), cols = pizza[0].size();
        vector<vector<int>> apples(rows + 1, vector<int>(cols + 1, 0));
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                apples[i][j] = (pizza[i][j] == 'A' ? 1 : 0)
                    + apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
            }
        }

        vector<vector<vector<long long>>> dp(k + 1, vector<vector<long long>>(rows, vector<long long>(cols, 0)));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                dp[1][i][j] = apples[i][j] > 0 ? 1 : 0;

        for (int pieces = 2; pieces <= k; pieces++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    long long sum = 0;
                    for (int r = i + 1; r < rows; r++) {
                        int topApples = apples[i][j] - apples[r][j];
                        if (topApples > 0) sum = (sum + dp[pieces-1][r][j]) % MOD;
                    }
                    for (int c = j + 1; c < cols; c++) {
                        int leftApples = apples[i][j] - apples[i][c];
                        if (leftApples > 0) sum = (sum + dp[pieces-1][i][c]) % MOD;
                    }
                    dp[pieces][i][j] = sum;
                }
            }
        }
        return (int)dp[k][0][0];
    }
};
