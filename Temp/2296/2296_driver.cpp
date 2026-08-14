#include <bits/stdc++.h>
using namespace std;
#include "2296.cpp"

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

vector<vector<string>> _rargsMixed() {
    string s; getline(cin,s);
    vector<vector<string>> v;
    int dep = 0; bool inq = false;
    vector<string> row; string tok; bool tokIsStr = false;
    for (char c : s) {
        if (c == '"') { inq = !inq; tokIsStr = true; continue; }
        if (inq) { tok += c; continue; }
        if (c == '[') { dep++; continue; }
        if (c == ']') {
            if (!tok.empty() || tokIsStr) { row.push_back(tok); tok = ""; tokIsStr = false; }
            dep--;
            if (dep == 1) { v.push_back(row); row.clear(); }
            continue;
        }
        if (c == ',') {
            if (!tok.empty() || tokIsStr) { row.push_back(tok); tok = ""; tokIsStr = false; }
            continue;
        }
        if (dep >= 2) tok += c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargsMixed();
        TextEditor* sol = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "TextEditor") { sol = new TextEditor(); out.push_back("null"); }
            else if (ops[i] == "addText") { sol->addText(args[i][0]); out.push_back("null"); }
            else if (ops[i] == "deleteText") { out.push_back(to_string(sol->deleteText(stoi(args[i][0])))); }
            else if (ops[i] == "cursorLeft") { out.push_back("\"" + sol->cursorLeft(stoi(args[i][0])) + "\""); }
            else if (ops[i] == "cursorRight") { out.push_back("\"" + sol->cursorRight(stoi(args[i][0])) + "\""); }
        }
        delete sol;
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) { if (i) cout << ", "; cout << out[i]; }
        cout << "]\n";
    }
    return 0;
}
