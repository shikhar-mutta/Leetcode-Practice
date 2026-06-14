#include <bits/stdc++.h>
using namespace std;
#include "430.cpp"

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

// Build a multilevel DLL from LeetCode 430 serialization.
// Levels are separated by runs of "null"; run length = 1-based index of the
// parent node (in the previous level) that the next level hangs off of.
Node* _build430(const string& line) {
    string body = line;
    if (body.size() >= 2 && body.front()=='[' && body.back()==']')
        body = body.substr(1, body.size()-2);

    vector<string> toks;
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) toks.push_back(t);

    vector<vector<int>> levels;
    vector<int> runBefore;            // nulls before each level
    int idx = 0, n = toks.size();
    while (idx < n) {
        int nulls = 0;
        while (idx < n && toks[idx]=="null") { nulls++; idx++; }
        if (idx >= n) break;          // trailing nulls
        vector<int> lvl;
        while (idx < n && toks[idx]!="null") { lvl.push_back(stoi(toks[idx])); idx++; }
        levels.push_back(lvl);
        runBefore.push_back(nulls);
    }

    vector<vector<Node*>> nodes(levels.size());
    for (size_t k = 0; k < levels.size(); k++) {
        Node* prev = nullptr;
        for (int v : levels[k]) {
            Node* nd = new Node();
            nd->val = v; nd->prev = prev; nd->next = nullptr; nd->child = nullptr;
            if (prev) prev->next = nd;
            prev = nd;
            nodes[k].push_back(nd);
        }
    }
    for (size_t k = 1; k < levels.size(); k++) {
        int pos = runBefore[k];        // 1-based parent index in level k-1
        nodes[k-1][pos-1]->child = nodes[k][0];
    }

    if (nodes.empty() || nodes[0].empty()) return nullptr;
    return nodes[0][0];
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line; getline(cin, line);
        Node* head = _build430(line);
        Solution sol;
        Node* res = sol.flatten(head);

        cout << "[";
        bool first = true;
        for (Node* p = res; p; p = p->next) {
            if (!first) cout << ",";
            cout << p->val;
            first = false;
        }
        cout << "]\n";
    }
    return 0;
}
