#include <bits/stdc++.h>
using namespace std;
#include "545.cpp"

vector<string> _rtok() {
    string s; getline(cin,s);
    vector<string> v;
    auto body = s.substr(1, s.size()-2);
    string cur;
    for (char c : body) {
        if (c == ',') { v.push_back(cur); cur=""; }
        else cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}
TreeNode* _rtree() {
    auto toks = _rtok();
    if (toks.empty() || toks[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(toks[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)toks.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < (int)toks.size()) {
            if (toks[i] != "null") { node->left = new TreeNode(stoi(toks[i])); q.push(node->left); }
            i++;
        }
        if (i < (int)toks.size()) {
            if (toks[i] != "null") { node->right = new TreeNode(stoi(toks[i])); q.push(node->right); }
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
        Solution sol;
        auto res = sol.boundaryOfBinaryTree(root);
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}
