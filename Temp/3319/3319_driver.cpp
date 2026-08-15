#include <bits/stdc++.h>
using namespace std;
#include "3319.cpp"

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

TreeNode* buildTree(const string& line) {
    // line like [5,3,6,5,2,5,7,1,8,null,null,6,8]
    string body = line.substr(1, line.size()-2);
    vector<string> tokens;
    string cur;
    for (char c : body) {
        if (c==',') { tokens.push_back(cur); cur=""; }
        else cur += c;
    }
    if (!cur.empty()) tokens.push_back(cur);
    if (tokens.empty() || tokens[0]=="null") return nullptr;

    vector<TreeNode*> nodes(tokens.size(), nullptr);
    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i] != "null") nodes[i] = new TreeNode(stoi(tokens[i]));
    }
    int idx = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty() && idx < (int)tokens.size()) {
        int cur_ = q.front(); q.pop();
        if (!nodes[cur_]) continue;
        if (idx < (int)tokens.size()) {
            nodes[cur_]->left = nodes[idx];
            q.push(idx);
            idx++;
        }
        if (idx < (int)tokens.size()) {
            nodes[cur_]->right = nodes[idx];
            q.push(idx);
            idx++;
        }
    }
    return nodes[0];
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line; getline(cin, line);
        TreeNode* root = buildTree(line);
        int k = _ri();
        Solution sol;
        auto res = sol.kthLargestPerfectSubtree(root, k);
        cout << res << "\n";
    }
    return 0;
}
