#include <bits/stdc++.h>
using namespace std;
#include "381.cpp"

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
        RandomizedCollection* rc = nullptr;
        multiset<int> present;
        bool ok = true;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "RandomizedCollection") {
                rc = new RandomizedCollection();
            } else if (ops[i] == "insert") {
                vector<int> a = _parseInts(args[i].substr(1, args[i].size() - 2));
                bool expected = present.count(a[0]) == 0;
                bool got = rc->insert(a[0]);
                present.insert(a[0]);
                if (got != expected) ok = false;
            } else if (ops[i] == "remove") {
                vector<int> a = _parseInts(args[i].substr(1, args[i].size() - 2));
                bool expected = present.count(a[0]) > 0;
                bool got = rc->remove(a[0]);
                if (expected) present.erase(present.find(a[0]));
                if (got != expected) ok = false;
            } else if (ops[i] == "getRandom") {
                int val = rc->getRandom();
                if (present.count(val) == 0) ok = false;
            }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
        delete rc;
    }
    return 0;
}
