#include <bits/stdc++.h>
using namespace std;
#include "428.cpp"

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

// N-ary tree level-order format: root val, then for each node (BFS order)
// that has children: a leading "null" delimiter followed by its children values
Node* _rtree() {
    auto toks = _rtok();
    if (toks.empty()) return nullptr;
    int i = 0;
    Node* root = new Node(stoi(toks[i++]));
    queue<Node*> q;
    q.push(root);
    while (!q.empty() && i < (int)toks.size()) {
        Node* node = q.front(); q.pop();
        if (toks[i] != "null") break; // malformed, but guard anyway
        i++; // skip leading null delimiter
        while (i < (int)toks.size() && toks[i] != "null") {
            Node* child = new Node(stoi(toks[i++]));
            node->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

string printNode(Node* root) {
    if (!root) return "";
    vector<string> tokens{to_string(root->val)};
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (node->children.empty()) continue;
        tokens.push_back("null");
        for (auto* c : node->children) {
            tokens.push_back(to_string(c->val));
            q.push(c);
        }
    }
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
        Node* root = _rtree();
        Codec codec;
        string data = codec.serialize(root);
        Node* back = codec.deserialize(data);
        cout << "[" << printNode(back) << "]\n";
    }
    return 0;
}
