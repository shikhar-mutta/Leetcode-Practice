#include <bits/stdc++.h>
using namespace std;
#include "1548.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

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
        auto roads = _rvvi();
        auto names = _rvs();
        auto targetPath = _rvs();

        Solution sol;
        auto path = sol.mostSimilar(n, roads, names, targetPath);

        // independent verification
        vector<vector<int>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        int m = targetPath.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int v = 0; v < n; v++) dp[0][v] = (names[v] != targetPath[0]) ? 1 : 0;
        for (int i = 1; i < m; i++) {
            for (int v = 0; v < n; v++) {
                int cost = (names[v] != targetPath[i]) ? 1 : 0;
                for (int u : adj[v]) dp[i][v] = min(dp[i][v], dp[i-1][u] + cost);
            }
        }
        int minCost = INT_MAX;
        for (int v = 0; v < n; v++) minCost = min(minCost, dp[m-1][v]);

        bool ok = (int)path.size() == m;
        if (ok) {
            int editDist = 0;
            for (int i = 0; i < m; i++) if (names[path[i]] != targetPath[i]) editDist++;
            for (int i = 1; i < m; i++) {
                bool connected = false;
                for (int u : adj[path[i]]) if (u == path[i-1]) connected = true;
                if (!connected) { ok = false; break; }
            }
            if (ok && editDist != minCost) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
