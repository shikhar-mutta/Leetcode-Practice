#include <bits/stdc++.h>
using namespace std;

static int _badVersion;

bool isBadVersion(int version) {
    return version >= _badVersion;
}

#include "278.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n = _ri();
        _badVersion = _ri();
        Solution sol;
        auto res = sol.firstBadVersion(n);
        cout << res << "\n";
    }
    return 0;
}
