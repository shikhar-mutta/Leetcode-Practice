#include <bits/stdc++.h>
using namespace std;
#include "1908.cpp"

vector<int> _rvi() {
    string s; getline(cin, s);
    vector<int> v; stringstream ss(s.substr(1, s.size() - 2));
    string t; while (getline(ss, t, ',')) { if (!t.empty()) v.push_back(stoi(t)); }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto piles = _rvi();
        Solution sol;
        cout << (sol.nimGame(piles) ? "true" : "false") << "\n";
    }
    return 0;
}
