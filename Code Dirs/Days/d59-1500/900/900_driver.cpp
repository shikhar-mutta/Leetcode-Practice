#include <bits/stdc++.h>
using namespace std;
#include "900.cpp"

// ── read helpers ──────────────────────────────────────────────────
int           _ri()  { string s; getline(cin,s); return stoi(s); }
long long     _rll() { string s; getline(cin,s); return stoll(s); }
double        _rd()  { string s; getline(cin,s); return stod(s); }
bool          _rb()  { string s; getline(cin,s); return s=="true"||s=="1"; }
string        _rs()  { string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s; }

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
vector<long long> _rvll() {
    string s; getline(cin,s);
    vector<long long> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoll(t)); }
    return v;
}
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
vector<vector<int>> _rvvi() {
    string s; getline(cin,s);
    vector<vector<int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<int> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur="";
            } else if (dep>0) cur+=c;
        } else if (dep>1) cur+=c;
    }
    return v;
}

vector<string> _rargsRaw() {
    string line; getline(cin, line);
    vector<string> raw;
    int dep = 0; string cur;
    for (char c : line) {
        if (c == '[') {
            dep++;
            if (dep >= 3) cur += c;
        } else if (c == ']') {
            if (dep >= 3) cur += c;
            dep--;
            if (dep == 1) { raw.push_back(cur); cur = ""; }
        } else if (c == ',') {
            if (dep >= 2) cur += c;
        } else {
            if (dep >= 2) cur += c;
        }
    }
    return raw;
}

vector<int> _parseIntArrayStr(const string &s) {
    vector<int> v;
    string body = s.substr(1, s.size() - 2);
    string cur;
    for (char c : body) {
        if (c == ',') { if (!cur.empty()) v.push_back(stoi(cur)); cur = ""; }
        else cur += c;
    }
    if (!cur.empty()) v.push_back(stoi(cur));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto rawArgs = _rargsRaw();
        RLEIterator* iter = nullptr;
        vector<string> outputs;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "RLEIterator") {
                auto encoding = _parseIntArrayStr(rawArgs[i]);
                iter = new RLEIterator(encoding);
                outputs.push_back("null");
            } else if (ops[i] == "next") {
                int n = stoi(rawArgs[i]);
                outputs.push_back(to_string(iter->next(n)));
            }
        }
        cout << "[";
        for (int i = 0; i < (int)outputs.size(); i++) { if (i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete iter;
    }
    return 0;
}
