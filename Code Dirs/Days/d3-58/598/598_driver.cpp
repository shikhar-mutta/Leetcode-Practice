#include <bits/stdc++.h>
using namespace std;

#include "598.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> ops(k, vector<int>(2));
        for (int i = 0; i < k; i++)
            cin >> ops[i][0] >> ops[i][1];
        Solution sol;
        cout << sol.maxCount(m, n, ops) << "\n";
    }
    return 0;
}
