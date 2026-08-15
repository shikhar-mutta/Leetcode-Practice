#include <bits/stdc++.h>
using namespace std;
#include "742.cpp"

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

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        TreeNode* root = _rtree();
        int k = _ri();
        Solution sol;
        auto res = sol.findClosestLeaf(root, k);
        cout << res << "\n";
    }
    return 0;
}
