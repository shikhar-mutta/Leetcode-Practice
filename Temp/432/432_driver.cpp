#include <bits/stdc++.h>
using namespace std;
#include "432.cpp"

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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> ops = _rvs();
        vector<string> args = _rargs();
        AllOne* ao = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            string arg = args[i].substr(1, args[i].size() - 2);
            if (arg.size() >= 2 && arg.front() == '"' && arg.back() == '"') arg = arg.substr(1, arg.size() - 2);
            if (ops[i] == "AllOne") {
                ao = new AllOne();
                out.push_back("null");
            } else if (ops[i] == "inc") {
                ao->inc(arg);
                out.push_back("null");
            } else if (ops[i] == "dec") {
                ao->dec(arg);
                out.push_back("null");
            } else if (ops[i] == "getMaxKey") {
                out.push_back("\"" + ao->getMaxKey() + "\"");
            } else if (ops[i] == "getMinKey") {
                out.push_back("\"" + ao->getMinKey() + "\"");
            }
        }
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
        delete ao;
    }
    return 0;
}
