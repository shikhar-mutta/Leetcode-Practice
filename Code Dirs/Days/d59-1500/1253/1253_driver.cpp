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

bool _validReconstruct(const vector<vector<int>>& res, int upper, int lower, const vector<int>& colsum) {
    int n = colsum.size();
    int twos = 0;
    long long total = 0;
    for (int c : colsum) { if (c == 2) twos++; total += c; }
    bool feasible = (upper + lower == total) && (upper >= twos) && (lower >= twos);

    if (!feasible) return res.empty();
    if (res.size() != 2) return false;
    if ((int)res[0].size() != n || (int)res[1].size() != n) return false;

    int rowSum0 = 0, rowSum1 = 0;
    for (int i = 0; i < n; i++) {
        if ((res[0][i] != 0 && res[0][i] != 1) || (res[1][i] != 0 && res[1][i] != 1)) return false;
        if (res[0][i] + res[1][i] != colsum[i]) return false;
        rowSum0 += res[0][i];
        rowSum1 += res[1][i];
    }
    return rowSum0 == upper && rowSum1 == lower;
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
        cout << (_validReconstruct(res, upper, lower, colsum) ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
