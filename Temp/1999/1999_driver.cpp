#include <bits/stdc++.h>
using namespace std;
#include "1999.cpp"

int _ri() { string s; getline(cin, s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int k = _ri();
        int digit1 = _ri();
        int digit2 = _ri();
        Solution sol;
        cout << sol.findInteger(k, digit1, digit2) << "\n";
    }
    return 0;
}
