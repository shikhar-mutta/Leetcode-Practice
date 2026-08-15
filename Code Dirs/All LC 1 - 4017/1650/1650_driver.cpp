#include <bits/stdc++.h>
using namespace std;
#include "1650.cpp"

Node* makeNode(int v) {
    Node* n = new Node();
    n->val = v;
    n->left = n->right = n->parent = nullptr;
    return n;
}

int main() {
    Node* n3 = makeNode(3);
    Node* n5 = makeNode(5);
    Node* n1 = makeNode(1);
    Node* n6 = makeNode(6);
    Node* n2 = makeNode(2);
    Node* n0 = makeNode(0);
    Node* n8 = makeNode(8);
    Node* n7 = makeNode(7);
    Node* n4 = makeNode(4);

    n3->left = n5; n3->right = n1; n5->parent = n3; n1->parent = n3;
    n5->left = n6; n5->right = n2; n6->parent = n5; n2->parent = n5;
    n1->left = n0; n1->right = n8; n0->parent = n1; n8->parent = n1;
    n2->left = n7; n2->right = n4; n7->parent = n2; n4->parent = n2;

    Solution sol;
    cout << sol.lowestCommonAncestor(n5, n1)->val << "\n";
    cout << sol.lowestCommonAncestor(n5, n4)->val << "\n";
    cout << sol.lowestCommonAncestor(n1, n0)->val << "\n";

    return 0;
}
