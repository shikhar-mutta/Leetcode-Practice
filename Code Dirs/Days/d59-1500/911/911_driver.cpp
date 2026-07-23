#include <bits/stdc++.h>
using namespace std;
#include "911.cpp"

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

pair<vector<int>, vector<int>> _parseTwoIntArrays(const string &s) {
    int dep = 0, pos = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '[') dep++;
        else if (s[i] == ']') { dep--; if (dep == 0) { pos = i; break; } }
    }
    string first = s.substr(0, pos + 1);
    string second = s.substr(pos + 2);
    return {_parseIntArrayStr(first), _parseIntArrayStr(second)};
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto rawArgs = _rargsRaw();
        TopVotedCandidate* candidate = nullptr;
        vector<string> outputs;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "TopVotedCandidate") {
                auto [persons, times] = _parseTwoIntArrays(rawArgs[i]);
                candidate = new TopVotedCandidate(persons, times);
                outputs.push_back("null");
            } else if (ops[i] == "q") {
                int time = stoi(rawArgs[i]);
                outputs.push_back(to_string(candidate->q(time)));
            }
        }
        cout << "[";
        for (int i = 0; i < (int)outputs.size(); i++) { if (i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete candidate;
    }
    return 0;
}
