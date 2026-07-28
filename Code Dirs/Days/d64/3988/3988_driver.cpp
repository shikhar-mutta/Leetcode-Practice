#include <bits/stdc++.h>
using namespace std;
#include "3988.cpp"

long long comb(int a, int b) {
    if (b < 0 || b > a) return 0;
    long long r = 1;
    for (int i = 0; i < b; i++) r = r * (a - i) / (i + 1);
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        Solution sol;
        auto grid = sol.createGrid(m, n, k);
        long long maxPaths = comb(m + n - 2, min(m, n) - 1);
        bool ok = true;
        if (k > maxPaths) {
            ok = grid.empty();
        } else {
            if ((int)grid.size() != m) ok = false;
            for (int i = 0; ok && i < m; i++) if ((int)grid[i].size() != n) ok = false;
            for (int i = 0; ok && i < m; i++)
                for (int j = 0; ok && j < n; j++)
                    if (grid[i][j] != '.' && grid[i][j] != '#') ok = false;
            if (ok) {
                vector<vector<long long>> dp(m, vector<long long>(n, 0));
                if (grid[0][0] == '.') dp[0][0] = 1;
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++) {
                        if (i == 0 && j == 0) continue;
                        if (grid[i][j] == '#') continue;
                        long long v = 0;
                        if (i > 0) v += dp[i - 1][j];
                        if (j > 0) v += dp[i][j - 1];
                        dp[i][j] = v;
                    }
                if (dp[m - 1][n - 1] != k) ok = false;
            }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
