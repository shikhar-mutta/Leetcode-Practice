#include <bits/stdc++.h>
using namespace std;
#include "653.cpp"

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

vector<string> _rtok2(const string& s) {
    vector<string> v;
    string body = s.substr(1, s.size()-2);
    string t; stringstream ss(body);
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(t);
    return v;
}

TreeNode* _rtree() {
    string s; getline(cin,s);
    auto v = _rtok2(s);
    if (v.empty() || v[0]=="null") return nullptr;
    TreeNode* root = new TreeNode(stoi(v[0]));
    queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (i < v.size() && !q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (i < v.size()) {
            if (v[i] != "null") { node->left = new TreeNode(stoi(v[i])); q.push(node->left); }
            i++;
        }
        if (i < v.size()) {
            if (v[i] != "null") { node->right = new TreeNode(stoi(v[i])); q.push(node->right); }
            i++;
        }
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        TreeNode* root = _rtree();
        int k = _ri();
        Solution sol;
        auto res = sol.findTarget(root, k);
        cout << (res ? "true" : "false") << "\n";
    }
    return 0;
}
