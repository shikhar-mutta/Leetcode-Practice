#include <bits/stdc++.h>
using namespace std;

#include "455.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];
        int m;
        cin >> m;
        vector<int> s(m);
        for (int i = 0; i < m; i++) cin >> s[i];
        Solution sol;
        cout << sol.findContentChildren(g, s) << "\n";
    }
    return 0;
}
