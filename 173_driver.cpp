#include <bits/stdc++.h>
using namespace std;
#include "173.cpp"

// ── read helpers ──────────────────────────────────────────────────
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

// splits the outer args-list line into each op's raw bracketed arg-group string
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) { v.push_back(cur); cur=""; }
            else if (dep>=1) cur+=c;
        } else if (dep>=2) cur+=c;
    }
    return v;
}

vector<string> _tokFromStr(const string& s) {
    // s is like "[7,3,15,null,null,9,20]"
    vector<string> toks;
    string body = s.substr(1, s.size()-2);
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) toks.push_back(t);
    return toks;
}

TreeNode* _treeFromTokens(const vector<string>& toks) {
    if (toks.empty() || toks[0]=="null") return nullptr;
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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargs();

        // first op is the constructor: args[0] is "[7,3,15,null,null,9,20]"
        TreeNode* root = _treeFromTokens(_tokFromStr(args[0]));
        BSTIterator* it = new BSTIterator(root);

        cout << "[null";
        for (size_t i = 1; i < ops.size(); i++) {
            cout << ", ";
            if (ops[i] == "next") cout << it->next();
            else if (ops[i] == "hasNext") cout << (it->hasNext() ? "true" : "false");
        }
        cout << "]\n";
        delete it;
    }
    return 0;
}
