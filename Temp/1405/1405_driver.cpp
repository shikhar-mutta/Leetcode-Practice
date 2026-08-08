#include <bits/stdc++.h>
using namespace std;
#include "1405.cpp"

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
        int a = _ri();
        int b = _ri();
        int c = _ri();
        Solution sol;
        auto res = sol.longestDiverseString(a, b, c);

        int cnt[3] = {0, 0, 0};
        bool ok = true;
        for (int i = 0; i < (int)res.size(); i++) {
            char ch = res[i];
            if (ch == 'a') cnt[0]++;
            else if (ch == 'b') cnt[1]++;
            else if (ch == 'c') cnt[2]++;
            else { ok = false; break; }
            if (i >= 2 && res[i] == res[i-1] && res[i] == res[i-2]) { ok = false; break; }
        }
        if (ok && (cnt[0] > a || cnt[1] > b || cnt[2] > c)) ok = false;

        // determine expected max achievable length via greedy bound (must be optimal length)
        int bestLen = 0;
        {
            priority_queue<pair<int,int>> pq;
            if (a > 0) pq.push({a, 0});
            if (b > 0) pq.push({b, 1});
            if (c > 0) pq.push({c, 2});
            vector<int> seq;
            while (!pq.empty()) {
                auto [cnt_, ch_] = pq.top(); pq.pop();
                int len = seq.size();
                if (len >= 2 && seq[len-1] == ch_ && seq[len-2] == ch_) {
                    if (pq.empty()) break;
                    auto [cnt2, ch2] = pq.top(); pq.pop();
                    seq.push_back(ch2);
                    cnt2--;
                    if (cnt2 > 0) pq.push({cnt2, ch2});
                    pq.push({cnt_, ch_});
                } else {
                    seq.push_back(ch_);
                    cnt_--;
                    if (cnt_ > 0) pq.push({cnt_, ch_});
                }
            }
            bestLen = seq.size();
        }
        if ((int)res.size() != bestLen) ok = false;

        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
