#include <bits/stdc++.h>
using namespace std;
#include "1357.cpp"

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
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') {
            dep++;
            if (dep>=3) cur+=c;
        } else if (c==']') {
            if (dep==2) { v.push_back(cur); cur=""; }
            else if (dep>=3) cur+=c;
            dep--;
        } else {
            if (dep>=2) cur+=c;
        }
    }
    return v;
}
vector<string> _splitTopBracket(const string &body) {
    vector<string> v;
    int depth = 0; string cur;
    for (char c : body) {
        if (c=='[') { depth++; cur += c; }
        else if (c==']') { depth--; cur += c; }
        else if (c==',' && depth==0) { v.push_back(cur); cur = ""; }
        else cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}
vector<int> _viFromStr(const string &s) {
    vector<int> v;
    string body = s.substr(1, s.size()-2);
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}
string _fmtDouble(double d) {
    ostringstream oss;
    oss << fixed << setprecision(10) << d;
    string s = oss.str();
    size_t dot = s.find('.');
    size_t last = s.find_last_not_of('0');
    if (last == dot) last++;
    s.erase(last+1);
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargs();

        Cashier *obj = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            auto parts = _splitTopBracket(args[i]);
            if (ops[i] == "Cashier") {
                int n = stoi(parts[0]);
                int discount = stoi(parts[1]);
                auto products = _viFromStr(parts[2]);
                auto prices = _viFromStr(parts[3]);
                obj = new Cashier(n, discount, products, prices);
                outputs.push_back("null");
            } else if (ops[i] == "getBill") {
                auto product = _viFromStr(parts[0]);
                auto amount = _viFromStr(parts[1]);
                double res = obj->getBill(product, amount);
                outputs.push_back(_fmtDouble(res));
            }
        }
        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) { if (i) cout << ","; cout << outputs[i]; }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
