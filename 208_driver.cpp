#include <bits/stdc++.h>
using namespace std;
#include "208.cpp"

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

// splits an args line like [[],["apple"],["app"]] into raw bracketed groups: "[]", "[\"apple\"]", ...
vector<string> _rargs() {
    string s; getline(cin, s);
    vector<string> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            dep++;
            if (dep > 1) cur += c;
        } else if (c == ']') {
            dep--;
            if (dep >= 1) cur += c;
            if (dep == 1) { v.push_back(cur); cur = ""; }
        } else if (dep > 1) {
            cur += c;
        }
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto rawArgs = _rargs();

        Trie* trie = nullptr;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            string op = ops[i];
            string raw = rawArgs[i];
            // strip surrounding [ ]
            string inner = raw.size() >= 2 ? raw.substr(1, raw.size() - 2) : "";
            string arg;
            if (inner.size() >= 2 && inner.front() == '"' && inner.back() == '"')
                arg = inner.substr(1, inner.size() - 2);

            if (op == "Trie") {
                trie = new Trie();
                out.push_back("null");
            } else if (op == "insert") {
                trie->insert(arg);
                out.push_back("null");
            } else if (op == "search") {
                out.push_back(trie->search(arg) ? "true" : "false");
            } else if (op == "startsWith") {
                out.push_back(trie->startsWith(arg) ? "true" : "false");
            }
        }

        cout << "[";
        for (size_t i = 0; i < out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
    }
    return 0;
}
