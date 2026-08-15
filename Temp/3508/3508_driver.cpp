#include <bits/stdc++.h>
using namespace std;
#include "3508.cpp"

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
        else if (c==']') {
            if (dep>=2) cur+=c;
            dep--;
            if (dep==1) { v.push_back(cur); cur=""; }
        } else if (dep>=2) cur+=c;
    }
    return v;
}
vector<int> _parseInts(const string& raw) {
    vector<int> v;
    if (raw.size() < 2) return v;
    string body = raw.substr(1, raw.size()-2);
    stringstream ss(body);
    string t; while(getline(ss,t,',')) if(!t.empty()) v.push_back(stoi(t));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargs();
        Router* rt = nullptr;
        string result = "[";
        for (size_t i = 0; i < ops.size(); i++) {
            if (i) result += ", ";
            auto a = _parseInts(args[i]);
            if (ops[i] == "Router") {
                rt = new Router(a[0]);
                result += "null";
            } else if (ops[i] == "addPacket") {
                bool r = rt->addPacket(a[0], a[1], a[2]);
                result += (r ? "true" : "false");
            } else if (ops[i] == "forwardPacket") {
                auto r = rt->forwardPacket();
                if (r.empty()) result += "[]";
                else result += "[" + to_string(r[0]) + ", " + to_string(r[1]) + ", " + to_string(r[2]) + "]";
            } else if (ops[i] == "getCount") {
                result += to_string(rt->getCount(a[0], a[1], a[2]));
            }
        }
        result += "]";
        cout << result << "\n";
        delete rt;
    }
    return 0;
}
