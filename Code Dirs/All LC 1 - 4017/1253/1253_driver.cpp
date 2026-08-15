#include <bits/stdc++.h>
using namespace std;
#include "1253.cpp"

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
        int upper = _ri();
        int lower = _ri();
        auto colsum = _rvi();
        Solution sol;
        auto res = sol.reconstructMatrix(upper, lower, colsum);

        bool ok;
        if (res.empty()) {
            // must genuinely be impossible
            int total = 0;
            for (int c : colsum) total += c;
            ok = (total != upper + lower);
            // also could be impossible for other reasons; brute-check feasibility
            if (ok) {
                // quick feasibility check matching greedy logic
                int u = upper, l = lower;
                bool feasible = true;
                for (int c : colsum) {
                    if (c == 2) { u--; l--; }
                    else if (c == 1) { if (u > 0) u--; else if (l > 0) l--; else { feasible = false; break; } }
                    if (u < 0 || l < 0) { feasible = false; break; }
                }
                if (u != 0 || l != 0) feasible = false;
                ok = !feasible;
            }
        } else {
            ok = res.size() == 2 && res[0].size() == colsum.size() && res[1].size() == colsum.size();
            if (ok) {
                int su = 0, sl = 0;
                for (int i = 0; i < (int)colsum.size(); i++) {
                    if (res[0][i] != 0 && res[0][i] != 1) ok = false;
                    if (res[1][i] != 0 && res[1][i] != 1) ok = false;
                    if (res[0][i] + res[1][i] != colsum[i]) ok = false;
                    su += res[0][i]; sl += res[1][i];
                }
                if (su != upper || sl != lower) ok = false;
            }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
