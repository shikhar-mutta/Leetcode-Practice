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

        // independent feasibility check (mirrors the solution's graph construction)
        bool feasible = true;
        {
            vector<int> g = origGroup;
            int groupCount = m;
            for (int i = 0; i < n; i++) if (g[i] == -1) g[i] = groupCount++;
            vector<vector<int>> itemAdj(n), groupAdj(groupCount);
            for (int i = 0; i < n; i++)
                for (int b : beforeItems[i]) {
                    itemAdj[b].push_back(i);
                    if (g[b] != g[i]) groupAdj[g[b]].push_back(g[i]);
                }
            auto topoOk = [](int sz, vector<vector<int>>& adj) {
                vector<int> indeg(sz, 0);
                for (int u = 0; u < sz; u++) for (int v : adj[u]) indeg[v]++;
                queue<int> q;
                for (int i = 0; i < sz; i++) if (indeg[i] == 0) q.push(i);
                int cnt = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop(); cnt++;
                    for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
                }
                return cnt == sz;
            };
            feasible = topoOk(n, itemAdj) && topoOk(groupCount, groupAdj);
        }

        bool ok = true;
        if (res.empty()) {
            ok = !feasible;
        } else {
            if ((int)res.size() != n) ok = false;
            vector<int> pos(n, -1);
            if (ok) {
                vector<bool> seen(n, false);
                for (int i = 0; i < n; i++) {
                    int item = res[i];
                    if (item < 0 || item >= n || seen[item]) { ok = false; break; }
                    seen[item] = true;
                    pos[item] = i;
                }
            }
            if (ok) {
                for (int i = 0; i < n && ok; i++) {
                    for (int b : beforeItems[i]) {
                        if (pos[b] >= pos[i]) { ok = false; break; }
                    }
                }
            }
            if (ok) {
                // group contiguity: items of same group must form a contiguous block
                unordered_map<int, pair<int,int>> range; // group -> (minPos,maxPos)
                for (int i = 0; i < n; i++) {
                    int g = origGroup[i];
                    if (g == -1) continue;
                    int p = pos[i];
                    if (!range.count(g)) range[g] = {p, p};
                    else { range[g].first = min(range[g].first, p); range[g].second = max(range[g].second, p); }
                }
                for (auto& [g, r] : range) {
                    int cnt = 0;
                    for (int i = 0; i < n; i++) if (origGroup[i] == g) cnt++;
                    if (r.second - r.first + 1 != cnt) { ok = false; break; }
                }
            }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
