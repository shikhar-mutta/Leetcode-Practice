#include <bits/stdc++.h>
using namespace std;
#include "133.cpp"

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
        auto adj = _rvvi();
        int n = adj.size();
        vector<Node*> nodes(n + 1, nullptr);
        for (int i = 1; i <= n; i++) nodes[i] = new Node(i);
        for (int i = 1; i <= n; i++)
            for (int nb : adj[i - 1]) nodes[i]->neighbors.push_back(nodes[nb]);

        Solution sol;
        Node* res = sol.cloneGraph(n ? nodes[1] : nullptr);

        if (!res) { cout << "[]\n"; continue; }
        unordered_map<int, Node*> byVal;
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(res); visited.insert(res);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            byVal[cur->val] = cur;
            for (auto nb : cur->neighbors)
                if (!visited.count(nb)) { visited.insert(nb); q.push(nb); }
        }
        cout << "[";
        for (int i = 1; i <= (int)byVal.size(); i++) {
            if (i > 1) cout << ",";
            cout << "[";
            auto &nbs = byVal[i]->neighbors;
            for (int j = 0; j < (int)nbs.size(); j++) { if (j) cout << ","; cout << nbs[j]->val; }
            cout << "]";
        }
        cout << "]\n";
    }
    return 0;
}
