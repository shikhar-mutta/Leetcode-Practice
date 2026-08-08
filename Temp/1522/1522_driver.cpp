#include <bits/stdc++.h>
using namespace std;
#include "1522.cpp"

Node* buildNaryTree(const vector<string>& toks) {
    if (toks.empty() || toks[0] == "null") return nullptr;
    Node* root = new Node(stoi(toks[0]));
    queue<Node*> q;
    q.push(root);
    size_t i = 2;
    while (!q.empty() && i < toks.size()) {
        Node* parent = q.front(); q.pop();
        while (i < toks.size() && toks[i] != "null") {
            Node* child = new Node(stoi(toks[i]));
            parent->children.push_back(child);
            q.push(child);
            i++;
        }
        i++;
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s; getline(cin, s);
        string body = s.substr(1, s.size()-2);
        vector<string> toks;
        stringstream ss(body);
        string tok;
        while (getline(ss, tok, ',')) toks.push_back(tok);

        Node* root = buildNaryTree(toks);
        Solution sol;
        cout << sol.diameter(root) << "\n";
    }
    return 0;
}
