#include <bits/stdc++.h>
using namespace std;

#include "463.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> grid[i][j];
        Solution sol;
        cout << sol.islandPerimeter(grid) << "\n";
    }
    return 0;
}
