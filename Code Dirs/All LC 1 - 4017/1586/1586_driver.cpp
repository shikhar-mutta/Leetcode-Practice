#include <bits/stdc++.h>
using namespace std;
#include "1586.cpp"

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

vector<string> extractGroupsRaw(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
            else cur += c;
        } else if (c == ']') {
            depth--;
            if (depth == 1) parts.push_back(cur);
            else cur += c;
        } else if (depth >= 2) {
            cur += c;
        }
    }
    return parts;
}

TreeNode* buildTree(const string& body) {
    if (body.empty() || body == "null") return nullptr;
    vector<string> toks;
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) toks.push_back(t);

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
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        BSTIterator* it = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            if (ops[i] == "BSTIterator") {
                string g = groups[i];
                if (!g.empty() && g.front() == '[' && g.back() == ']') g = g.substr(1, g.size() - 2);
                TreeNode* root = buildTree(g);
                it = new BSTIterator(root);
                cout << "null";
            } else if (ops[i] == "next") {
                cout << it->next();
            } else if (ops[i] == "hasNext") {
                cout << (it->hasNext() ? "true" : "false");
            } else if (ops[i] == "prev") {
                cout << it->prev();
            } else if (ops[i] == "hasPrev") {
                cout << (it->hasPrev() ? "true" : "false");
            }
        }
        cout << "]\n";
        delete it;
    }
    return 0;
}
