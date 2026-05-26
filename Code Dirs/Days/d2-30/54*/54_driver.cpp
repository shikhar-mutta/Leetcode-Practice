#include <bits/stdc++.h>
using namespace std;

#include "54.cpp"

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
        vector<int> ans = sol.spiralOrder(matrix);
        for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
    return 0;
}
