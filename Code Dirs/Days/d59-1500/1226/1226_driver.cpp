#include <bits/stdc++.h>
using namespace std;
#include "1226.cpp"

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
        DiningPhilosophers dp;
        mutex logMtx;
        int counter = 0;
        vector<array<int,5>> events(n);

        vector<thread> threads;
        for (int i = 0; i < n; i++) {
            threads.emplace_back([&, i]() {
                dp.wantsToEat(i,
                    [&, i]() { lock_guard<mutex> l(logMtx); events[i][0] = counter++; },
                    [&, i]() { lock_guard<mutex> l(logMtx); events[i][1] = counter++; },
                    [&, i]() { lock_guard<mutex> l(logMtx); events[i][2] = counter++; },
                    [&, i]() { lock_guard<mutex> l(logMtx); events[i][3] = counter++; },
                    [&, i]() { lock_guard<mutex> l(logMtx); events[i][4] = counter++; });
            });
        }
        for (auto& th : threads) th.join();

        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            for (int k = 0; k < 4; k++)
                if (events[i][k] >= events[i][k + 1]) ok = false;

        for (int i = 0; i < n && ok; i++) {
            int j = (i + 1) % n;
            if (j == i) continue;
            bool overlap = !(events[i][4] < events[j][0] || events[j][4] < events[i][0]);
            if (overlap) ok = false;
        }

        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
