#include <bits/stdc++.h>
using namespace std;
#include "117.cpp"

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
    auto buildTree = [](vector<string>& vs) -> Node* {
        if (vs.empty() || vs[0] == "null") return nullptr;
        Node* root = new Node(stoi(vs[0]));
        queue<Node*> q; q.push(root);
        for (int i = 1; i < (int)vs.size(); ) {
            Node* node = q.front(); q.pop();
            if (i < (int)vs.size() && vs[i] != "null") { node->left = new Node(stoi(vs[i])); q.push(node->left); } i++;
            if (i < (int)vs.size() && vs[i] != "null") { node->right = new Node(stoi(vs[i])); q.push(node->right); } i++;
        }
        return root;
    };
    auto printTree = [](Node* root) {
        if (!root) { cout << "[]\n"; return; }
        cout << "[";
        queue<Node*> q; q.push(root);
        bool first = true;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node* node = q.front(); q.pop();
                if (!first) cout << ","; first = false;
                cout << node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << ",#";
        }
        cout << "]\n";
    };
    while (t--) {
        auto vs = _rvs(); Node* root = buildTree(vs);
        Solution sol;
        auto res = sol.connect(root);
        printTree(res);
    }
    return 0;
}
