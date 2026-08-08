#include <bits/stdc++.h>
using namespace std;
#include "1430.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
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
        auto arr = _rvi();
        Solution sol;
        cout << (sol.isValidSequence(root, arr) ? "true" : "false") << "\n";
    }
    return 0;
}
