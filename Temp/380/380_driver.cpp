#include <bits/stdc++.h>
using namespace std;
#include "380.cpp"

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
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>=2) cur+=c; }
        else if (c==']') { if(dep>=2) cur+=c; dep--; if(dep==1){ v.push_back(cur); cur=""; } }
        else if (dep>=2) cur+=c;
    }
    return v;
}
vector<int> _parseInts(const string& s) {
    vector<int> v;
    stringstream ss(s);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> ops = _rvs();
        vector<string> args = _rargs();
        RandomizedSet* rs = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "RandomizedSet") {
                rs = new RandomizedSet();
                out.push_back("null");
            } else if (ops[i] == "insert") {
                vector<int> a = _parseInts(args[i].substr(1, args[i].size() - 2));
                out.push_back(rs->insert(a[0]) ? "true" : "false");
            } else if (ops[i] == "remove") {
                vector<int> a = _parseInts(args[i].substr(1, args[i].size() - 2));
                out.push_back(rs->remove(a[0]) ? "true" : "false");
            } else if (ops[i] == "getRandom") {
                out.push_back(to_string(rs->getRandom()));
            }
        }
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
        delete rs;
    }
    return 0;
}
