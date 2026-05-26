#include <bits/stdc++.h>
using namespace std;

#include "118.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numRows;
        cin >> numRows;
        Solution sol;
        vector<vector<int>> ans = sol.generate(numRows);
        for (auto& row : ans) {
            for (int i = 0; i < (int)row.size(); i++) cout << row[i] << " \n"[i == (int)row.size() - 1];
        }
    }
    return 0;
}
