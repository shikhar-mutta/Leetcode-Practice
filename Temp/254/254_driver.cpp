#include <bits/stdc++.h>
using namespace std;
#include "254.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n = _ri();
        Solution sol;
        auto res = sol.getFactors(n);
        sort(res.begin(), res.end());
        if (res.empty()) cout << "\n";
        for (auto& row : res) {
            for (int i = 0; i < (int)row.size(); i++) { if (i) cout << " "; cout << row[i]; }
            cout << "\n";
        }
    }
    return 0;
}
