#include <bits/stdc++.h>
using namespace std;

int rand7() { return rand() % 7 + 1; }

#include "470.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n = _ri();
        Solution sol;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int r = sol.rand10();
            if (r < 1 || r > 10) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
