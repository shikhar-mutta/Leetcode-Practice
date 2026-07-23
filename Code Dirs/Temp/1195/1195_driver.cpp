#include <bits/stdc++.h>
using namespace std;
#include "1195.cpp"

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
        FizzBuzz fb(n);
        vector<string> out;
        mutex outMtx;

        auto printFizz = [&]() { lock_guard<mutex> lock(outMtx); out.push_back("fizz"); };
        auto printBuzz = [&]() { lock_guard<mutex> lock(outMtx); out.push_back("buzz"); };
        auto printFizzBuzz = [&]() { lock_guard<mutex> lock(outMtx); out.push_back("fizzbuzz"); };
        auto printNumber = [&](int x) { lock_guard<mutex> lock(outMtx); out.push_back(to_string(x)); };

        thread t1([&]() { fb.fizz(printFizz); });
        thread t2([&]() { fb.buzz(printBuzz); });
        thread t3([&]() { fb.fizzbuzz(printFizzBuzz); });
        thread t4([&]() { fb.number(printNumber); });
        t1.join(); t2.join(); t3.join(); t4.join();

        for (size_t i = 0; i < out.size(); i++) { if (i) cout << " "; cout << out[i]; }
        cout << "\n";
    }
    return 0;
}
