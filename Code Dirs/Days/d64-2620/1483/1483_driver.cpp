#include <bits/stdc++.h>
using namespace std;
#include "1483.cpp"

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
        auto ops = _rvs();          // ["TreeAncestor","getKthAncestor",...]
        string argsLine; getline(cin, argsLine);
        // argsLine like: [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
        // split top-level bracketed groups
        vector<string> argGroups;
        int depth = 0; string cur;
        for (size_t i = 1; i + 1 < argsLine.size(); i++) {
            char c = argsLine[i];
            if (c == '[') { depth++; if (depth == 1) { cur = ""; continue; } }
            if (c == ']') { depth--; if (depth == 0) { argGroups.push_back(cur); continue; } }
            if (depth >= 1) cur += c;
        }

        TreeAncestor* ta = nullptr;
        vector<string> results;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "TreeAncestor") {
                // argGroups[i] = "7,[-1,0,0,1,1,2,2]"
                string g = argGroups[i];
                size_t br = g.find('[');
                int n = stoi(g.substr(0, g.find(',')));
                string arrStr = g.substr(br + 1, g.size() - br - 2);
                vector<int> parent;
                stringstream ss(arrStr);
                string tkn;
                while (getline(ss, tkn, ',')) if (!tkn.empty()) parent.push_back(stoi(tkn));
                ta = new TreeAncestor(n, parent);
                results.push_back("null");
            } else {
                string g = argGroups[i];
                stringstream ss(g);
                string a, b;
                getline(ss, a, ',');
                getline(ss, b, ',');
                int node = stoi(a), k = stoi(b);
                int res = ta->getKthAncestor(node, k);
                results.push_back(to_string(res));
            }
        }
        cout << "[";
        for (size_t i = 0; i < results.size(); i++) {
            cout << results[i];
            if (i + 1 < results.size()) cout << ", ";
        }
        cout << "]\n";
        delete ta;
    }
    return 0;
}
