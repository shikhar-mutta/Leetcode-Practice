#include <bits/stdc++.h>
using namespace std;
#include "497.cpp"

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
// Splits an args line like "[[[1,2,3]],[],[],[],[],[]]" into the raw
// (still-bracketed) argument-list text for each op: {"[1,2,3]", "", "", ...}
vector<string> _rargs() {
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
        } else {
            if (dep >= 2) cur += c;
        }
    }
    return raw;
}

vector<vector<int>> _parseVVI(const string& s) {
    vector<vector<int>> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 2) cur += c; }
        else if (c == ']') {
            dep--;
            if (dep == 1) {
                vector<int> row; stringstream ss(cur);
                string t; while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur = "";
            } else if (dep > 0) cur += c;
        } else if (dep > 1) cur += c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto argsRaw = _rargs();
        auto rects = _parseVVI(argsRaw[0]);
        Solution sol(rects);

        bool ok = true;
        const int trials = 200000;
        vector<long long> hits(rects.size(), 0);
        for (int i = 0; i < trials && ok; i++) {
            auto p = sol.pick();
            int x = p[0], y = p[1];
            int owner = -1;
            for (size_t r = 0; r < rects.size(); r++) {
                if (x >= rects[r][0] && x <= rects[r][2] && y >= rects[r][1] && y <= rects[r][3]) { owner = r; break; }
            }
            if (owner == -1) ok = false;
            else hits[owner]++;
        }

        if (ok) {
            long long totalArea = 0;
            vector<long long> area(rects.size());
            for (size_t r = 0; r < rects.size(); r++) {
                area[r] = (long long)(rects[r][2] - rects[r][0] + 1) * (rects[r][3] - rects[r][1] + 1);
                totalArea += area[r];
            }
            for (size_t r = 0; r < rects.size(); r++) {
                double expectedFrac = (double)area[r] / totalArea;
                double actualFrac = (double)hits[r] / trials;
                if (fabs(expectedFrac - actualFrac) > 0.03) ok = false;
            }
        }

        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
