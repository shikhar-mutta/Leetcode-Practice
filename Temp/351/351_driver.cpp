#include <bits/stdc++.h>
using namespace std;
#include "351.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int m = _ri();
        int n = _ri();
        Solution sol;
        cout << sol.numberOfPatterns(m, n) << "\n";
    }
    return 0;
}
