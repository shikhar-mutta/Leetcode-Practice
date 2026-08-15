#include <bits/stdc++.h>
using namespace std;
#include "1666.cpp"

Node* makeNode(int v) {
    Node* n = new Node();
    n->val = v;
    n->left = n->right = n->parent = nullptr;
    return n;
}

string preorder(Node* root) {
    if (!root) return "";
    string s = to_string(root->val);
    string l = preorder(root->left);
    string r = preorder(root->right);
    if (!l.empty()) s += " " + l;
    if (!r.empty()) s += " " + r;
    return s;
}

int main() {
    Node* n3 = makeNode(3);
    Node* n5 = makeNode(5);
    Node* n1 = makeNode(1);
    Node* n6 = makeNode(6);
    Node* n2 = makeNode(2);
    Node* n7 = makeNode(7);
    Node* n4 = makeNode(4);

    n3->left = n5; n3->right = n1; n5->parent = n3; n1->parent = n3;
    n5->left = n6; n5->right = n2; n6->parent = n5; n2->parent = n5;
    n2->left = n7; n2->right = n4; n7->parent = n2; n4->parent = n2;

    {
        Solution sol;
        Node* newRoot = sol.flipBinaryTree(n3, n7);
        cout << preorder(newRoot) << "\n";
    }

    return 0;
}
