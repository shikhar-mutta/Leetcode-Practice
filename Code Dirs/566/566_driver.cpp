#include <bits/stdc++.h>
using namespace std;

#include "566.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r, c;
        cin >> r >> c;
        Solution sol;
        auto res = sol.matrixReshape(mat, r, c);
        for (auto& row : res) {
            for (int j = 0; j < (int)row.size(); j++) {
                if (j) cout << " ";
                cout << row[j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
