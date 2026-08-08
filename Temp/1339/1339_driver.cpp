#include <bits/stdc++.h>
using namespace std;
#include "1339.cpp"

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

TreeNode* _rtree() {
    string s; getline(cin,s);
    string body = s.substr(1, s.size()-2);
    vector<string> toks;
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) toks.push_back(t);
    if (toks.empty() || toks[0] == "null") return nullptr;

    vector<TreeNode*> nodes(toks.size(), nullptr);
    for (size_t i = 0; i < toks.size(); i++)
        if (toks[i] != "null") nodes[i] = new TreeNode(stoi(toks[i]));

    TreeNode* root = nodes[0];
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < toks.size()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < toks.size()) { cur->left = nodes[i]; if (nodes[i]) q.push(nodes[i]); i++; }
        if (i < toks.size()) { cur->right = nodes[i]; if (nodes[i]) q.push(nodes[i]); i++; }
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        TreeNode* root = _rtree();
        Solution sol;
        auto res = sol.maxProduct(root);
        cout << res << "\n";
    }
    return 0;
}
