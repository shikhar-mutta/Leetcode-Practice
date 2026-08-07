#include <bits/stdc++.h>
using namespace std;
#include "425.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto words = _rvs();
        Solution sol;
        auto res = sol.wordSquares(words);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << "[";
            for (int j = 0; j < (int)res[i].size(); j++) {
                if (j) cout << ",";
                cout << "\"" << res[i][j] << "\"";
            }
            cout << "]";
        }
        cout << "]\n";
    }
    return 0;
}
