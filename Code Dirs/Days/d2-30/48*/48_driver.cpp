#include <bits/stdc++.h>
using namespace std;

#include "48.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution sol;
        sol.rotate(matrix);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cout << matrix[i][j] << " \n"[j == n - 1];
    }
    return 0;
}
