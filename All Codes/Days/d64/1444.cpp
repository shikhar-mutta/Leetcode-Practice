// Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m, K;
    const int MOD = 1e9 + 7;
    vector<vector<int>> suf; // suf[r][c] = apples in rows>=r, cols>=c
    vector<vector<vector<int>>> memo;

    bool hasApple(int r, int c) { return suf[r][c] > 0; }

    int solve(int r, int c, int k) {
        if (r >= n || c >= m) return 0;
        if (!hasApple(r, c)) return 0;
        if (k == 1) return 1;
        if (memo[k][r][c] != -1) return memo[k][r][c];
        long long res = 0;
        for (int i = r + 1; i < n; i++) {
            if (suf[r][c] - suf[i][c] > 0)
                res = (res + solve(i, c, k - 1)) % MOD;
        }
        for (int j = c + 1; j < m; j++) {
            if (suf[r][c] - suf[r][j] > 0)
                res = (res + solve(r, j, k - 1)) % MOD;
        }
        return memo[k][r][c] = (int)res;
    }
public:
    int ways(vector<string>& pizza, int k) {
        n = pizza.size(); m = pizza[0].size(); K = k;
        suf.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                suf[i][j] = suf[i+1][j] + suf[i][j+1] - suf[i+1][j+1] + (pizza[i][j] == 'A');
        memo.assign(k + 1, vector<vector<int>>(n, vector<int>(m, -1)));
        return solve(0, 0, k);
    }
};
