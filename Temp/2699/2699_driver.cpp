#include <bits/stdc++.h>
using namespace std;
#include "2699.cpp"

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
        auto edges = _rvvi();
        int source = _ri();
        int destination = _ri();
        int target = _ri();
        Solution sol;
        auto origEdges = edges;
        auto res = sol.modifiedGraphEdges(n, edges, source, destination, target);

        if (res.empty()) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        bool valid = (res.size() == origEdges.size());
        if (valid) {
            for (size_t i = 0; i < res.size(); i++) {
                if (res[i][0] != origEdges[i][0] || res[i][1] != origEdges[i][1]) { valid = false; break; }
                if (origEdges[i][2] != -1 && res[i][2] != origEdges[i][2]) { valid = false; break; }
                if (origEdges[i][2] == -1 && res[i][2] < 1) { valid = false; break; }
            }
        }

        if (valid) {
            vector<vector<pair<int,int>>> adj(n);
            for (auto &e : res) {
                adj[e[0]].push_back({e[1], e[2]});
                adj[e[1]].push_back({e[0], e[2]});
            }
            vector<long long> dist(n, LLONG_MAX);
            dist[source] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            pq.push({0, source});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto &[v, w] : adj[u]) {
                    if (d + w < dist[v]) { dist[v] = d + w; pq.push({dist[v], v}); }
                }
            }
            if (dist[destination] != target) valid = false;
        }

        cout << (valid ? "VALID" : "INVALID") << "\n";
    }
    return 0;
}
