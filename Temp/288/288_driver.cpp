#include <bits/stdc++.h>
using namespace std;
#include "288.cpp"

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
string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict = _rvs();
        vector<string> queries = _rvs();
        ValidWordAbbr sol(dict);
        vector<string> res;
        for (auto& q : queries) res.push_back(sol.isUnique(q) ? "true" : "false");
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << res[i];
        }
        cout << "]\n";
    }
    return 0;
}
