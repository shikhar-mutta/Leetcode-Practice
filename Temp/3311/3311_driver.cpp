#include <bits/stdc++.h>
using namespace std;
#include "3311.cpp"

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
        Solution sol;
        auto res = sol.constructGridLayout(n, edges);

        set<pair<int,int>> edgeSet;
        for (auto& e : edges) edgeSet.insert({min(e[0],e[1]), max(e[0],e[1])});

        bool valid = true;
        int rows = res.size();
        int cols = rows > 0 ? res[0].size() : 0;
        if ((long long)rows * cols != n) valid = false;

        set<int> seen;
        if (valid) {
            for (auto& row : res) {
                if ((int)row.size() != cols) { valid = false; break; }
                for (int x : row) {
                    if (x < 0 || x >= n || seen.count(x)) { valid = false; break; }
                    seen.insert(x);
                }
                if (!valid) break;
            }
        }
        if (valid && (int)seen.size() != n) valid = false;

        set<pair<int,int>> computedEdges;
        if (valid) {
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (c + 1 < cols) {
                        int a = res[r][c], b = res[r][c+1];
                        computedEdges.insert({min(a,b), max(a,b)});
                    }
                    if (r + 1 < rows) {
                        int a = res[r][c], b = res[r+1][c];
                        computedEdges.insert({min(a,b), max(a,b)});
                    }
                }
            }
            if (computedEdges != edgeSet) valid = false;
        }

        cout << (valid ? "VALID" : "INVALID") << "\n";
    }
    return 0;
}
