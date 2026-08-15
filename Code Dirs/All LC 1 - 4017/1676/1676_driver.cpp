#include <bits/stdc++.h>
using namespace std;
#include "1676.cpp"

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
        vector<TreeNode*> nodes = {n4, n7};
        cout << sol.lowestCommonAncestor(root, nodes)->val << "\n";
    }
    {
        Solution sol2;
        vector<TreeNode*> nodes = {n1};
        cout << sol2.lowestCommonAncestor(root, nodes)->val << "\n";
    }
    {
        Solution sol3;
        vector<TreeNode*> nodes = {n7, n6, n2, n4};
        cout << sol3.lowestCommonAncestor(root, nodes)->val << "\n";
    }

    return 0;
}
