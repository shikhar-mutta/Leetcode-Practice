#include <bits/stdc++.h>
using namespace std;
#include "1490.cpp"

Node* buildNaryTree(const vector<string>& toks) {
    if (toks.empty() || toks[0] == "null") return nullptr;
    Node* root = new Node(stoi(toks[0]));
    queue<Node*> q;
    q.push(root);
    size_t i = 2; // skip root val and the null right after it
    while (!q.empty() && i < toks.size()) {
        Node* parent = q.front(); q.pop();
        while (i < toks.size() && toks[i] != "null") {
            Node* child = new Node(stoi(toks[i]));
            parent->children.push_back(child);
            q.push(child);
            i++;
        }
        i++; // skip the null separator
    }
    return root;
}

bool checkClone(Node* orig, Node* copy) {
    if (!orig && !copy) return true;
    if (!orig || !copy) return false;
    if (orig == copy) return false; // must be a genuine deep copy
    if (orig->val != copy->val) return false;
    if (orig->children.size() != copy->children.size()) return false;
    for (size_t i = 0; i < orig->children.size(); i++) {
        if (!checkClone(orig->children[i], copy->children[i])) return false;
    }
    return true;
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
        Node* clone = sol.cloneTree(root);

        cout << (checkClone(root, clone) ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
