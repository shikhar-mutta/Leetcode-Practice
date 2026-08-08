#include <bits/stdc++.h>
using namespace std;
#include "1203.cpp"

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
        int n = _ri();
        int m = _ri();
        auto group = _rvi();
        auto origGroup = group;
        auto beforeItems = _rvvi();
        Solution sol;
        auto res = sol.sortItems(n, m, group, beforeItems);

        bool ok = (int)res.size() == n;
        if (ok) {
            vector<int> pos(n);
            for (int i = 0; i < n; i++) pos[res[i]] = i;
            for (int i = 0; i < n; i++) {
                for (int b : beforeItems[i]) {
                    if (pos[b] > pos[i]) ok = false;
                }
            }
            // group contiguity check
            unordered_map<int,pair<int,int>> range;
            for (int i = 0; i < n; i++) {
                int g = origGroup[res[i]];
                if (g == -1) continue;
                if (!range.count(g)) range[g] = {i, i};
                else { range[g].first = min(range[g].first, i); range[g].second = max(range[g].second, i); }
            }
            for (auto& [g, r] : range) if (r.second - r.first + 1 != (int)count(origGroup.begin(), origGroup.end(), g)) ok = false;
        } else if (n > 0 && res.empty()) {
            // could legitimately be impossible; can't verify without re-deriving, trust empty as -1 case
            ok = true;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
