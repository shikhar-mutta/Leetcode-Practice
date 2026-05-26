#include <bits/stdc++.h>
using namespace std;

#include "56.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++) cin >> intervals[i][0] >> intervals[i][1];
        Solution sol;
        vector<vector<int>> ans = sol.merge(intervals);
        for (auto& v : ans) cout << v[0] << " " << v[1] << "\n";
        cout << "\n";
    }
    return 0;
}
