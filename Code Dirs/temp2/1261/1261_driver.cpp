#include <bits/stdc++.h>
using namespace std;
#include "1261.cpp"

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

vector<string> _tokFromStr(const string& s) {
    vector<string> v;
    string cur;
    for (char c : s) {
        if (c == ',') { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}
TreeNode* _treeFromTokens(const vector<string>& toks) {
    if (toks.empty() || toks[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(toks[0]));
    queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (i < toks.size() && !q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < toks.size()) {
            if (toks[i] != "null") { cur->left = new TreeNode(stoi(toks[i])); q.push(cur->left); }
            i++;
        }
        if (i < toks.size()) {
            if (toks[i] != "null") { cur->right = new TreeNode(stoi(toks[i])); q.push(cur->right); }
            i++;
        }
    }
    return root;
}
// Splits an ops-args line like "[[[-1,null,-1]],[1],[2]]" into raw
// per-op arg-group strings, keeping each group's own brackets intact.
vector<string> _rargs() {
    string s; getline(cin, s);
    vector<string> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            dep++;
            if (dep >= 2) cur += c;
        } else if (c == ']') {
            if (dep >= 2) cur += c;
            dep--;
            if (dep == 1) { v.push_back(cur); cur = ""; }
        } else if (c == ',') {
            if (dep >= 2) cur += c;
        } else {
            if (dep >= 1) cur += c;
        }
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargs();

        string treeArg = args[0].substr(2, args[0].size() - 4);
        TreeNode* root = _treeFromTokens(_tokFromStr(treeArg));
        FindElements fe(root);

        vector<string> out;
        out.push_back("null");
        for (size_t i = 1; i < ops.size(); i++) {
            string a = args[i].substr(1, args[i].size() - 2);
            int target = stoi(a);
            out.push_back(fe.find(target) ? "true" : "false");
        }

        cout << "[";
        for (size_t i = 0; i < out.size(); i++) { if (i) cout << ","; cout << out[i]; }
        cout << "]\n";
    }
    return 0;
}
