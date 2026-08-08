#include <bits/stdc++.h>
using namespace std;
#include "1602.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

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

TreeNode* findByVal(TreeNode* node, int val) {
    if (!node) return nullptr;
    if (node->val == val) return node;
    TreeNode* l = findByVal(node->left, val);
    if (l) return l;
    return findByVal(node->right, val);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        TreeNode* root = _rtree();
        int uVal = _ri();
        TreeNode* u = findByVal(root, uVal);
        Solution sol;
        TreeNode* res = sol.findNearestRightNode(root, u);
        if (res) cout << res->val << "\n";
        else cout << "null\n";
    }
    return 0;
}
