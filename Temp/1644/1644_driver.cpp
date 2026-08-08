#include <bits/stdc++.h>
using namespace std;
#include "1644.cpp"

int main() {
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2, n7, n4);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n5 = new TreeNode(5, n6, n2);
    TreeNode* n1 = new TreeNode(1, n0, n8);
    TreeNode* root = new TreeNode(3, n5, n1);

    {
        Solution sol;
        TreeNode* res = sol.lowestCommonAncestor(root, n5, n1);
        cout << (res ? res->val : -1) << "\n";
    }
    {
        Solution sol2;
        TreeNode* res = sol2.lowestCommonAncestor(root, n5, n4);
        cout << (res ? res->val : -1) << "\n";
    }
    {
        TreeNode* notInTree = new TreeNode(10);
        Solution sol3;
        TreeNode* res = sol3.lowestCommonAncestor(root, n5, notInTree);
        cout << (res ? res->val : -1) << "\n";
    }

    return 0;
}
