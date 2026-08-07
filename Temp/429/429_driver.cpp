#include <bits/stdc++.h>
using namespace std;
#include "429.cpp"

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
    if (toks.empty()) return nullptr;
    int i = 0;
    Node* root = new Node(stoi(toks[i++]));
    queue<Node*> q;
    q.push(root);
    while (!q.empty() && i < (int)toks.size()) {
        Node* node = q.front(); q.pop();
        if (toks[i] != "null") break;
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
        auto res = sol.levelOrder(root);
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << "[";
            for (int j = 0; j < (int)res[i].size(); j++) {
                if (j) cout << ",";
                cout << res[i][j];
            }
            cout << "]";
        }
        cout << "]\n";
    }
    return 0;
}
