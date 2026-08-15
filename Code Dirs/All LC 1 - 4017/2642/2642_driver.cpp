#include <bits/stdc++.h>
using namespace std;
#include "2642.cpp"

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

struct Val {
    bool isArr = false;
    string str;
    vector<Val> arr;
};

Val parseValue(const string &s, size_t &i) {
    Val v;
    if (s[i] == '[') {
        v.isArr = true;
        i++;
        if (s[i] == ']') { i++; return v; }
        while (true) {
            v.arr.push_back(parseValue(s, i));
            if (s[i] == ',') { i++; continue; }
            if (s[i] == ']') { i++; break; }
        }
        return v;
    }
    string cur;
    while (i < s.size() && s[i] != ',' && s[i] != ']') cur += s[i++];
    v.str = cur;
    return v;
}

vector<int> toIntArr(const Val &v) {
    vector<int> r;
    for (auto &e : v.arr) r.push_back(stoi(e.str));
    return r;
}
vector<vector<int>> toIntArrArr(const Val &v) {
    vector<vector<int>> r;
    for (auto &e : v.arr) r.push_back(toIntArr(e));
    return r;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        size_t idx = 0;
        Val allArgs = parseValue(argsLine, idx);

        Graph* g = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            string &op = ops[i];
            Val &args = allArgs.arr[i];
            if (op == "Graph") {
                int n = stoi(args.arr[0].str);
                vector<vector<int>> edges = toIntArrArr(args.arr[1]);
                g = new Graph(n, edges);
                outputs.push_back("null");
            } else if (op == "addEdge") {
                vector<int> edge = toIntArr(args.arr[0]);
                g->addEdge(edge);
                outputs.push_back("null");
            } else if (op == "shortestPath") {
                int a = stoi(args.arr[0].str);
                int b = stoi(args.arr[1].str);
                outputs.push_back(to_string(g->shortestPath(a, b)));
            }
        }

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ", ";
            cout << outputs[i];
        }
        cout << "]\n";
        delete g;
    }
    return 0;
}
