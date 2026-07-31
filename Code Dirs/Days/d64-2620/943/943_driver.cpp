#include <bits/stdc++.h>
using namespace std;
#include "943.cpp"

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
        auto words = _rvs();
        Solution sol;
        auto res = sol.shortestSuperstring(words);

        bool ok = true;
        for (auto& w : words) if (res.find(w) == string::npos) { ok = false; break; }
        // brute-force the true minimal length via permutations (n is small in tests)
        if (ok) {
            int n = words.size();
            vector<int> perm(n);
            iota(perm.begin(), perm.end(), 0);
            int bestLen = INT_MAX;
            do {
                string s = words[perm[0]];
                for (int k = 1; k < n; k++) {
                    string& a = s;
                    string& b = words[perm[k]];
                    int maxLen = min(a.size(), b.size());
                    int ov = 0;
                    for (int len = maxLen; len > 0; len--) {
                        if (a.substr(a.size() - len) == b.substr(0, len)) { ov = len; break; }
                    }
                    s += b.substr(ov);
                }
                bestLen = min(bestLen, (int)s.size());
            } while (next_permutation(perm.begin(), perm.end()));
            if ((int)res.size() != bestLen) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
