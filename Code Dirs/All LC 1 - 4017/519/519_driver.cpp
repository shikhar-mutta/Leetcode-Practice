#include <bits/stdc++.h>
using namespace std;
#include "519.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int m = _ri();
        int n = _ri();
        int flips = _ri();
        Solution sol(m, n);
        set<pair<int,int>> seen;
        bool ok = true;
        for (int i = 0; i < flips; i++) {
            auto p = sol.flip();
            if (p[0] < 0 || p[0] >= m || p[1] < 0 || p[1] >= n) ok = false;
            pair<int,int> pr = {p[0], p[1]};
            if (seen.count(pr)) ok = false;
            seen.insert(pr);
        }
        sol.reset();
        auto p2 = sol.flip();
        if (p2[0] < 0 || p2[0] >= m || p2[1] < 0 || p2[1] >= n) ok = false;
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
