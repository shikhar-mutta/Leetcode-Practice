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

// split [[],["apple"],["app"]] into one string arg per op ("" for [])
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if (dep==2) cur=""; }
        else if (c==']') { if (dep==2) { string t; for(char x:cur) if(x!='"') t+=x; v.push_back(t); } dep--; }
        else if (dep==2) cur += c;
    }
    return v;
}

int main() {
    string dummy; getline(cin, dummy);   // count line (unreliable for design problems)
    string opsLine;
    while (getline(cin, opsLine)) {
        if (opsLine.empty()) continue;
        vector<string> ops;
        {
            bool in=false; string cur;
            for (char c : opsLine.substr(1, opsLine.size()-2)) {
                if (c=='"') { in=!in; continue; }
                if (c==',' && !in) { ops.push_back(cur); cur=""; continue; }
                cur += c;
            }
            if (!cur.empty()) ops.push_back(cur);
        }
        auto args = _rargs();
        Trie *trie = nullptr;
        cout << "[";
        for (size_t i=0;i<ops.size();i++) {
            if (i) cout << ", ";
            if (ops[i]=="Trie")            { trie = new Trie(); cout << "null"; }
            else if (ops[i]=="insert")     { trie->insert(args[i]); cout << "null"; }
            else if (ops[i]=="search")     { cout << (trie->search(args[i]) ? "true" : "false"); }
            else if (ops[i]=="startsWith") { cout << (trie->startsWith(args[i]) ? "true" : "false"); }
        }
        cout << "]\n";
    }
    return 0;
}
