#include <bits/stdc++.h>
using namespace std;
#include "2408.cpp"

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
    int dep = 0; string cur; bool inStr = false;
    for (char c : line) {
        if (!inStr && c == '[') { dep++; if (dep >= 3) cur += c; continue; }
        if (!inStr && c == ']') { if (dep >= 3) cur += c; dep--; if (dep == 1) { raw.push_back(cur); cur = ""; } continue; }
        if (c == '"') { inStr = !inStr; if (dep >= 2) cur += c; continue; }
        if (dep >= 2) cur += c;
    }
    return raw;
}

vector<string> _splitTopLevel(const string& raw) {
    vector<string> toks;
    int dep = 0; string cur; bool inStr = false;
    for (char c : raw) {
        if (c == '"') { inStr = !inStr; cur += c; continue; }
        if (!inStr && c == '[') { dep++; cur += c; continue; }
        if (!inStr && c == ']') { dep--; cur += c; continue; }
        if (!inStr && c == ',' && dep == 0) { toks.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) toks.push_back(cur);
    return toks;
}

string _stripQuotes(const string& s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') return s.substr(1, s.size()-2);
    return s;
}

vector<string> _parseStrArray(const string& arr) {
    string body = arr.substr(1, arr.size()-2);
    vector<string> v;
    bool inStr = false; string cur;
    for (char c : body) {
        if (c=='"') { inStr=!inStr; continue; }
        if (c==',' && !inStr) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<int> _parseIntArrayBracketed(const string& arr) {
    string body = arr.substr(1, arr.size()-2);
    vector<int> v; stringstream ss(body);
    string t; while(getline(ss,t,',')) if(!t.empty()) v.push_back(stoi(t));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto rawArgs = _rargsRaw();
        SQL* sql = nullptr;
        vector<string> outputs;
        for (int i = 0; i < (int)ops.size(); i++) {
            auto parts = _splitTopLevel(rawArgs[i]);
            if (ops[i] == "SQL") {
                auto names = _parseStrArray(parts[0]);
                auto columns = _parseIntArrayBracketed(parts[1]);
                sql = new SQL(names, columns);
                outputs.push_back("null");
            } else if (ops[i] == "ins") {
                string name = _stripQuotes(parts[0]);
                auto row = _parseStrArray(parts[1]);
                bool res = sql->ins(name, row);
                outputs.push_back(res ? "true" : "false");
            } else if (ops[i] == "rmv") {
                string name = _stripQuotes(parts[0]);
                int rowId = stoi(parts[1]);
                sql->rmv(name, rowId);
                outputs.push_back("null");
            } else if (ops[i] == "sel") {
                string name = _stripQuotes(parts[0]);
                int rowId = stoi(parts[1]);
                int columnId = stoi(parts[2]);
                string res = sql->sel(name, rowId, columnId);
                outputs.push_back("\"" + res + "\"");
            } else if (ops[i] == "exp") {
                string name = _stripQuotes(parts[0]);
                auto res = sql->exp(name);
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) { if (j) s += ","; s += "\"" + res[j] + "\""; }
                s += "]";
                outputs.push_back(s);
            }
        }
        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) { if (i) cout << ","; cout << outputs[i]; }
        cout << "]\n";
        delete sql;
    }
    return 0;
}
