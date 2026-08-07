#include <bits/stdc++.h>
using namespace std;
#include "544.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n = _ri();
        Solution sol;
        cout << "\"" << sol.findContestMatch(n) << "\"\n";
    }
    return 0;
}
