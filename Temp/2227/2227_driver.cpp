#include <bits/stdc++.h>
using namespace std;
#include "2227.cpp"

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

// per op: list of argument-slots; each slot: list of strings
// (single string args -> 1-element list; array args -> multi-element list)
vector<vector<vector<string>>> _rargsNested() {
    string s; getline(cin,s);
    vector<vector<vector<string>>> perOp;
    int dep = 0; bool inq = false;
    vector<vector<string>> opSlots;
    vector<string> slot;
    string tok;
    for (char c : s) {
        if (c == '"') {
            if (!inq) { tok = ""; }
            else {
                if (dep == 2) opSlots.push_back({tok});
                else if (dep == 3) slot.push_back(tok);
            }
            inq = !inq;
            continue;
        }
        if (inq) { tok += c; continue; }
        if (c == '[') { dep++; continue; }
        if (c == ']') {
            if (dep == 3) { opSlots.push_back(slot); slot.clear(); }
            else if (dep == 2) { perOp.push_back(opSlots); opSlots.clear(); }
            dep--;
            continue;
        }
        // commas and other chars outside quotes: ignore
    }
    return perOp;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargsNested();
        Encrypter* sol = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "Encrypter") {
                vector<string> keysStr = args[i][0];
                vector<char> keys;
                for (auto& k : keysStr) keys.push_back(k[0]);
                vector<string> values = args[i][1];
                vector<string> dictionary = args[i][2];
                sol = new Encrypter(keys, values, dictionary);
                out.push_back("null");
            } else if (ops[i] == "encrypt") {
                out.push_back("\"" + sol->encrypt(args[i][0][0]) + "\"");
            } else if (ops[i] == "decrypt") {
                out.push_back(to_string(sol->decrypt(args[i][0][0])));
            }
        }
        delete sol;
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) { if (i) cout << ", "; cout << out[i]; }
        cout << "]\n";
    }
    return 0;
}
