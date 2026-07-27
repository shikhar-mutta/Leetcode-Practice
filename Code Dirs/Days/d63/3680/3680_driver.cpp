#include <bits/stdc++.h>
using namespace std;
#include "3680.cpp"

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
        Solution sol;
        auto res = sol.generateSchedule(n);

        bool ok = true;
        if (n < 4) {
            ok = res.empty();
        } else {
            int total = n * (n - 1);
            if ((int)res.size() != total) ok = false;
            vector<vector<bool>> seen(n, vector<bool>(n, false));
            int prevA = -1, prevB = -1;
            for (int i = 0; ok && i < (int)res.size(); i++) {
                int u = res[i][0], v = res[i][1];
                if (u < 0 || u >= n || v < 0 || v >= n || u == v) { ok = false; break; }
                if (seen[u][v]) { ok = false; break; }
                seen[u][v] = true;
                if (i > 0 && (u == prevA || u == prevB || v == prevA || v == prevB)) { ok = false; break; }
                prevA = u; prevB = v;
            }
            if (ok) {
                for (int u = 0; u < n && ok; u++)
                    for (int v = 0; v < n && ok; v++)
                        if (u != v && !seen[u][v]) ok = false;
            }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
