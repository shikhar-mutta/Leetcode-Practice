#include <bits/stdc++.h>
using namespace std;
#include "1740.cpp"

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

    Solution sol;
    cout << sol.findDistance(root, 5, 0) << "\n";
    cout << sol.findDistance(root, 5, 7) << "\n";
    cout << sol.findDistance(root, 5, 5) << "\n";

    return 0;
}
