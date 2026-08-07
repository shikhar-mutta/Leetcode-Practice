#include <bits/stdc++.h>
using namespace std;
#include "210.cpp"

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
        int numCourses = _ri();
        auto prerequisites = _rvvi();
        Solution sol;
        auto res = sol.findOrder(numCourses, prerequisites);
        bool feasible = true;
        {
            vector<int> indeg(numCourses, 0);
            vector<vector<int>> adj(numCourses);
            for (auto& p : prerequisites) { adj[p[1]].push_back(p[0]); indeg[p[0]]++; }
            queue<int> q;
            for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
            int processed = 0;
            while (!q.empty()) { int u = q.front(); q.pop(); processed++; for (int v : adj[u]) if (--indeg[v]==0) q.push(v); }
            feasible = (processed == numCourses);
        }
        bool ok;
        if (!feasible) {
            ok = res.empty();
        } else {
            ok = (int)res.size() == numCourses;
            vector<int> pos(numCourses, -1);
            for (int i = 0; i < (int)res.size(); i++) pos[res[i]] = i;
            if (ok) for (int i = 0; i < numCourses && ok; i++) if (pos[i] == -1) ok = false;
            if (ok) for (auto& p : prerequisites) if (pos[p[1]] >= pos[p[0]]) { ok = false; break; }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
