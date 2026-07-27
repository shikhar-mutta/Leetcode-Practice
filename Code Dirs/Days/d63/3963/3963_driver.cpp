#include <bits/stdc++.h>
using namespace std;
#include "3963.cpp"

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int m; cin >> m;
        int n; cin >> n;
        cin.ignore();
        Solution sol;
        auto grid = sol.createGrid(m, n);

        bool ok = (int)grid.size() == m;
        for (auto& row : grid) {
            if ((int)row.size() != n) ok = false;
            for (char c : row) if (c != '.' && c != '#') ok = false;
        }
        if (ok && (grid[0][0] != '.' || grid[m-1][n-1] != '.')) ok = false;

        if (ok) {
            // count paths using DP, capped at 2 to detect >1
            vector<vector<long long>> dp(m, vector<long long>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '#') continue;
                    if (i == 0 && j == 0) { dp[i][j] = 1; continue; }
                    long long ways = 0;
                    if (i > 0) ways += dp[i-1][j];
                    if (j > 0) ways += dp[i][j-1];
                    dp[i][j] = min(ways, (long long)2);
                }
            }
            if (dp[m-1][n-1] != 1) ok = false;
        }

        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
