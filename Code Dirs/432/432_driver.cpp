#include <bits/stdc++.h>
using namespace std;
#include "432.cpp"

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

// Parse an array-of-arrays of string args, e.g. [[],["hello"],[],["leet"]].
// Each inner array yields its (0 or 1) string argument.
vector<vector<string>> _rargs() {
    string s; getline(cin, s);
    vector<vector<string>> res;
    int depth = 0; bool inStr = false; string token; vector<string> cur;
    for (char c : s) {
        if (c == '[') { if (++depth == 2) cur.clear(); continue; }
        if (c == ']') { if (depth == 2) res.push_back(cur); depth--; continue; }
        if (depth == 2) {
            if (c == '"') {
                if (inStr) { cur.push_back(token); token.clear(); }
                inStr = !inStr;
            } else if (inStr) token += c;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> ops  = _rvs();
        vector<vector<string>> args = _rargs();

        AllOne* obj = nullptr;
        cout << "[";
        for (size_t i = 0; i < ops.size(); i++) {
            if (i) cout << ", ";
            const string& op = ops[i];
            if (op == "AllOne")        { obj = new AllOne();        cout << "null"; }
            else if (op == "inc")      { obj->inc(args[i][0]);      cout << "null"; }
            else if (op == "dec")      { obj->dec(args[i][0]);      cout << "null"; }
            else if (op == "getMaxKey") cout << "\"" << obj->getMaxKey() << "\"";
            else if (op == "getMinKey") cout << "\"" << obj->getMinKey() << "\"";
        }
        cout << "]\n";
    }
    return 0;
}
