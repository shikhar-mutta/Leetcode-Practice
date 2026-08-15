#include <bits/stdc++.h>
using namespace std;
#include "460.cpp"

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
        LFUCache* cache = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            vector<int> a = _parseInts(args[i].substr(1, args[i].size() - 2));
            if (ops[i] == "LFUCache") {
                cache = new LFUCache(a[0]);
                out.push_back("null");
            } else if (ops[i] == "get") {
                out.push_back(to_string(cache->get(a[0])));
            } else if (ops[i] == "put") {
                cache->put(a[0], a[1]);
                out.push_back("null");
            }
        }
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
        delete cache;
    }
    return 0;
}
