#include <bits/stdc++.h>
using namespace std;
#include "1485.cpp"

void collectVals(NodeCopy* node, set<int>& vals) {
    if (!node) return;
    vals.insert(node->val);
    collectVals(node->left, vals);
    collectVals(node->right, vals);
}

bool checkStructure(Node* orig, NodeCopy* copy) {
    if (!orig && !copy) return true;
    if (!orig || !copy) return false;
    if (orig->val != copy->val) return false;
    if ((orig->random == nullptr) != (copy->random == nullptr)) return false;
    if (orig->random && orig->random->val != copy->random->val) return false;
    return checkStructure(orig->left, copy->left) && checkStructure(orig->right, copy->right);
}

int main() {
    // Build test tree:
    //      1
    //     / \
    //    2   3
    // random: 1->3, 2->1, 3->null
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->left = n2;
    n1->right = n3;
    n1->random = n3;
    n2->random = n1;
    n3->random = nullptr;

    Solution sol;
    NodeCopy* copyRoot = sol.copyRandomBinaryTree(n1);

    bool ok = checkStructure(n1, copyRoot);
    cout << (ok ? "PASS" : "FAIL") << "\n";
    return 0;
}
