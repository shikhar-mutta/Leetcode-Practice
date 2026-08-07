#include <bits/stdc++.h>
using namespace std;
#include "478.cpp"

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        double radius, xc, yc;
        int n;
        cin >> radius >> xc >> yc >> n;
        cin.ignore();
        Solution sol(radius, xc, yc);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            auto p = sol.randPoint();
            double dx = p[0] - xc, dy = p[1] - yc;
            if (dx*dx + dy*dy > radius*radius + 1e-9) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
