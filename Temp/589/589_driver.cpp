#include <bits/stdc++.h>
using namespace std;
#include "589.cpp"

vector<string> _rtok() {
    string s; getline(cin, s);
    vector<string> toks;
    string body = s.substr(1, s.size()-2);
    string cur;
    for (char c : body) {
        if (c == ',') { toks.push_back(cur); cur.clear(); }
        else cur += c;
    }
    if (!cur.empty()) toks.push_back(cur);
    return toks;
}

Node* _rtree() {
    auto toks = _rtok();
    if (toks.empty()) return nullptr;
    int i = 0;
    Node* root = new Node(stoi(toks[i++]));
    queue<Node*> q;
    q.push(root);
    while (!q.empty() && i < (int)toks.size()) {
        Node* node = q.front(); q.pop();
        if (toks[i] != "null") continue;
        i++;
        while (i < (int)toks.size() && toks[i] != "null") {
            Node* child = new Node(stoi(toks[i++]));
            node->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        Node* root = _rtree();
        Solution sol;
        auto res = sol.preorder(root);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) { if(i) cout << ","; cout << res[i]; }
        cout << "]\n";
    }
    return 0;
}
