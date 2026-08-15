#include <bits/stdc++.h>
using namespace std;
#include "510.cpp"

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
Node* _rtree() {
    auto toks = _rtok();
    if (toks.empty() || toks[0] == "null") return nullptr;
    Node* root = new Node();
    root->val = stoi(toks[0]);
    root->left = root->right = root->parent = nullptr;
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)toks.size()) {
        Node* node = q.front(); q.pop();
        if (i < (int)toks.size()) {
            if (toks[i] != "null") {
                Node* c = new Node();
                c->val = stoi(toks[i]); c->left = c->right = nullptr; c->parent = node;
                node->left = c;
                q.push(c);
            }
            i++;
        }
        if (i < (int)toks.size()) {
            if (toks[i] != "null") {
                Node* c = new Node();
                c->val = stoi(toks[i]); c->left = c->right = nullptr; c->parent = node;
                node->right = c;
                q.push(c);
            }
            i++;
        }
    }
    return root;
}
Node* _find(Node* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    Node* l = _find(root->left, val);
    if (l) return l;
    return _find(root->right, val);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        Node* root = _rtree();
        string s; getline(cin, s);
        int pval = stoi(s);
        Node* p = _find(root, pval);
        Solution sol;
        Node* res = sol.inorderSuccessor(p);
        if (res) cout << res->val << "\n";
        else cout << "null\n";
    }
    return 0;
}
