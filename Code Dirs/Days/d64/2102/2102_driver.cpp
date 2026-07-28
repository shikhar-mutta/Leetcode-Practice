#include <bits/stdc++.h>
using namespace std;
#include "2102.cpp"

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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        vector<string> argGroups;
        int depth = 0; string cur;
        for (size_t i = 1; i + 1 < argsLine.size(); i++) {
            char c = argsLine[i];
            if (c == '[') { depth++; if (depth == 1) { cur = ""; continue; } }
            if (c == ']') { depth--; if (depth == 0) { argGroups.push_back(cur); continue; } }
            if (depth >= 1) cur += c;
        }

        SORTracker* sys = nullptr;
        vector<string> results;
        for (size_t i = 0; i < ops.size(); i++) {
            string& op = ops[i];
            string& g = argGroups[i];
            if (op == "SORTracker") {
                sys = new SORTracker();
                results.push_back("null");
            } else if (op == "add") {
                stringstream ss(g); string a, b;
                getline(ss, a, ',');
                getline(ss, b, ',');
                if (a.size() >= 2 && a.front() == '"' && a.back() == '"') a = a.substr(1, a.size() - 2);
                sys->add(a, stoi(b));
                results.push_back("null");
            } else if (op == "get") {
                results.push_back("\"" + sys->get() + "\"");
            }
        }
        cout << "[";
        for (size_t i = 0; i < results.size(); i++) {
            cout << results[i];
            if (i + 1 < results.size()) cout << ", ";
        }
        cout << "]\n";
        delete sys;
    }
    return 0;
}
