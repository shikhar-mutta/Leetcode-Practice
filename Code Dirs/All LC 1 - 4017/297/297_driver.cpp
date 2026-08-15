#include <bits/stdc++.h>
using namespace std;
#include "297.cpp"

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

string _serializeTree(TreeNode* root) {
    if (!root) return "";
    vector<string> tokens;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (!node) { tokens.push_back("null"); continue; }
        tokens.push_back(to_string(node->val));
        q.push(node->left);
        q.push(node->right);
    }
    while (!tokens.empty() && tokens.back() == "null") tokens.pop_back();
    string res;
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (i) res += ",";
        res += tokens[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        TreeNode* root = _rtree();
        Codec codec;
        string data = codec.serialize(root);
        TreeNode* back = codec.deserialize(data);
        cout << "[" << _serializeTree(back) << "]\n";
    }
    return 0;
}
