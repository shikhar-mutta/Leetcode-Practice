#include <bits/stdc++.h>
using namespace std;

#include "73.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution sol;
        sol.setZeroes(matrix);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << matrix[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}
