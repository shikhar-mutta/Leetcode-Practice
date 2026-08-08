#include <bits/stdc++.h>
using namespace std;
#include "1891.cpp"

vector<int> _rvi() {
    string s; getline(cin, s);
    vector<int> v; stringstream ss(s.substr(1, s.size() - 2));
    string t; while (getline(ss, t, ',')) { if (!t.empty()) v.push_back(stoi(t)); }
    return v;
}
int _ri() { string s; getline(cin, s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ribbons = _rvi();
        int k = _ri();
        Solution sol;
        cout << sol.maxLength(ribbons, k) << "\n";
    }
    return 0;
}
