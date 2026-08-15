#include <bits/stdc++.h>
using namespace std;
#include "1469.cpp"

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
        auto res = sol.findLonelyNodes(root);
        for (int i = 0; i < (int)res.size(); i++) { if (i) cout << " "; cout << res[i]; }
        cout << "\n";
    }
    return 0;
}
