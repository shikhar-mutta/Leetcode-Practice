#include <bits/stdc++.h>
using namespace std;
#include "1256.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int num = _ri();
        Solution sol;
        cout << sol.encode(num) << "\n";
    }
    return 0;
}
