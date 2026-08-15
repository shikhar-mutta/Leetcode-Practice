#include <bits/stdc++.h>
using namespace std;
#include "1506.cpp"

Node* buildNaryTree(const vector<string>& toks, vector<Node*>& allNodes) {
    if (toks.empty() || toks[0] == "null") return nullptr;
    Node* root = new Node(stoi(toks[0]));
    allNodes.push_back(root);
    queue<Node*> q;
    q.push(root);
    size_t i = 2;
    while (!q.empty() && i < toks.size()) {
        Node* parent = q.front(); q.pop();
        while (i < toks.size() && toks[i] != "null") {
            Node* child = new Node(stoi(toks[i]));
            allNodes.push_back(child);
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

        vector<Node*> allNodes;
        Node* root = buildNaryTree(toks, allNodes);

        // shuffle order to simulate the "tree" list not necessarily starting with root
        mt19937 rng(42);
        shuffle(allNodes.begin(), allNodes.end(), rng);

        Solution sol;
        Node* found = sol.findRoot(allNodes);
        cout << (found == root ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
