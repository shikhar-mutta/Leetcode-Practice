#include <bits/stdc++.h>
using namespace std;
#include "285.cpp"

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

TreeNode* _find(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* l = _find(root->left, val);
    if (l) return l;
    return _find(root->right, val);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        TreeNode* root = _rtree();
        string s; getline(cin, s);
        int pval = stoi(s);
        TreeNode* p = _find(root, pval);
        Solution sol;
        TreeNode* res = sol.inorderSuccessor(root, p);
        if (res) cout << res->val << "\n";
        else cout << "null\n";
    }
    return 0;
}
