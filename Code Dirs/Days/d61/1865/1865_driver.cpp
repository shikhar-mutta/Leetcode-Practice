#include <bits/stdc++.h>
using namespace std;
#include "1865.cpp"

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
// raw per-op argument groups, keeping nested brackets intact
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>=3) cur+=c; }
        else if (c==']') {
            if (dep>=3) cur+=c;
            dep--;
            if (dep==1) { v.push_back(cur); cur=""; }
        } else if (dep>=2) cur+=c;
    }
    return v;
}
vector<string> _splitTop(const string &s) {
    vector<string> parts; int dep=0; string cur;
    for (char c : s) {
        if (c=='[') dep++;
        if (c==']') dep--;
        if (c==',' && dep==0) { parts.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) parts.push_back(cur);
    return parts;
}
vector<int> _parseIntArr(const string &s) {
    string body = s;
    if (!body.empty() && body.front()=='[' && body.back()==']')
        body = body.substr(1, body.size()-2);
    vector<int> v; stringstream ss(body);
    string t; while(getline(ss,t,',')) if(!t.empty()) v.push_back(stoi(t));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargs();

        auto ctor = _splitTop(args[0]);
        vector<int> nums1 = _parseIntArr(ctor[0]);
        vector<int> nums2 = _parseIntArr(ctor[1]);
        FindSumPairs sol(nums1, nums2);

        vector<string> out = {"null"};
        for (size_t i = 1; i < ops.size(); i++) {
            auto a = _parseIntArr(args[i]);
            if (ops[i] == "count")
                out.push_back(to_string(sol.count(a[0])));
            else if (ops[i] == "add") {
                sol.add(a[0], a[1]);
                out.push_back("null");
            }
        }

        cout << "[";
        for (size_t i = 0; i < out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
    }
    return 0;
}
