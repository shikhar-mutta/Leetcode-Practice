#include <bits/stdc++.h>
using namespace std;
#include "269.cpp"

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
        auto res = sol.alienOrder(words);

        unordered_set<char> allChars;
        for (auto& w : words) for (char c : w) allChars.insert(c);

        // ground-truth feasibility via the same edge-derivation + Kahn's algorithm
        bool feasible = true;
        {
            unordered_map<char, unordered_set<char>> adj;
            unordered_map<char, int> indeg;
            for (char c : allChars) { adj[c]; indeg[c]; }
            for (int i = 0; i + 1 < (int)words.size() && feasible; i++) {
                string& a = words[i]; string& b = words[i+1];
                int minLen = min(a.size(), b.size());
                bool found = false;
                for (int j = 0; j < minLen; j++) {
                    if (a[j] != b[j]) {
                        if (!adj[a[j]].count(b[j])) { adj[a[j]].insert(b[j]); indeg[b[j]]++; }
                        found = true;
                        break;
                    }
                }
                if (!found && a.size() > b.size()) feasible = false;
            }
            if (feasible) {
                queue<char> q;
                for (auto& [c, d] : indeg) if (d == 0) q.push(c);
                int processed = 0;
                while (!q.empty()) {
                    char c = q.front(); q.pop(); processed++;
                    for (char nb : adj[c]) if (--indeg[nb] == 0) q.push(nb);
                }
                feasible = (processed == (int)indeg.size());
            }
        }

        bool ok;
        if (res.empty()) {
            ok = !feasible || allChars.empty();
        } else {
            unordered_set<char> seen(res.begin(), res.end());
            ok = (seen.size() == res.size()) && (seen == allChars);
            if (ok) {
                unordered_map<char,int> pos;
                for (int i = 0; i < (int)res.size(); i++) pos[res[i]] = i;
                for (int i = 0; i + 1 < (int)words.size() && ok; i++) {
                    string& a = words[i]; string& b = words[i+1];
                    int minLen = min(a.size(), b.size());
                    bool found = false;
                    for (int j = 0; j < minLen; j++) {
                        if (a[j] != b[j]) { if (pos[a[j]] > pos[b[j]]) ok = false; found = true; break; }
                    }
                    if (!found && a.size() > b.size()) ok = false;
                }
            }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
