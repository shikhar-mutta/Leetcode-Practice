#include <bits/stdc++.h>
using namespace std;
#include "1973.cpp"

int main() {
    {
        TreeNode* n2 = new TreeNode(2);
        TreeNode* n1 = new TreeNode(1);
        TreeNode* n3 = new TreeNode(3, n2, n1);
        TreeNode* n4 = new TreeNode(4);
        TreeNode* root = new TreeNode(10, n3, n4);
        Solution sol;
        cout << sol.equalToDescendants(root) << "\n";
    }
    {
        TreeNode* n3 = new TreeNode(3);
        TreeNode* root = new TreeNode(2, n3, nullptr);
        Solution sol;
        cout << sol.equalToDescendants(root) << "\n";
    }
    {
        TreeNode* n0a = new TreeNode(0);
        TreeNode* n0b = new TreeNode(0);
        TreeNode* root = new TreeNode(0, n0a, n0b);
        Solution sol;
        cout << sol.equalToDescendants(root) << "\n";
    }

    return 0;
}
