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

// split top-level comma-separated groups inside the outer [...] (depth-1 boundary)
vector<string> splitTopLevel(const string& s) {
    vector<string> groups;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 2) cur += c; }
        else if (c == ']') { dep--; if (dep >= 2) cur += c; if (dep == 1) { groups.push_back(cur); cur.clear(); } }
        else if (dep > 1) cur += c;
    }
    return groups;
}

vector<int> parseIntList(const string& s) {
    vector<int> v;
    string body = (!s.empty() && s[0] == '[') ? s.substr(1, s.size()-2) : s;
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

vector<vector<int>> parseIntMatrix(const string& s) {
    vector<vector<int>> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; }
        else if (c == ']') { dep--; if (dep == 1) { v.push_back(parseIntList("[" + cur + "]")); cur.clear(); } }
        else if (dep == 2) cur += c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string rawArgs; getline(cin, rawArgs);
        auto groups = splitTopLevel(rawArgs);

        Graph* obj = nullptr;
        vector<string> results;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "Graph") {
                // groups[i] = "4,[[0,2,5],[0,1,2],[1,2,1],[3,0,3]]"
                size_t commaPos = groups[i].find(',');
                int n = stoi(groups[i].substr(0, commaPos));
                auto edges = parseIntMatrix(groups[i].substr(commaPos + 1));
                obj = new Graph(n, edges);
                results.push_back("null");
            } else if (ops[i] == "addEdge") {
                auto edge = parseIntList(groups[i]);
                obj->addEdge(edge);
                results.push_back("null");
            } else if (ops[i] == "shortestPath") {
                auto inner = parseIntList(groups[i]);
                int res = obj->shortestPath(inner[0], inner[1]);
                results.push_back(to_string(res));
            }
        }
        delete obj;
        cout << "[";
        for (size_t i = 0; i < results.size(); i++) { if (i) cout << ", "; cout << results[i]; }
        cout << "]\n";
    }
    return 0;
}
