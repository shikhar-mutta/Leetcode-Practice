#include <bits/stdc++.h>
using namespace std;
#include "1660.cpp"

string preorder(TreeNode* root) {
    if (!root) return "";
    string s = to_string(root->val);
    string l = preorder(root->left);
    string r = preorder(root->right);
    if (!l.empty()) s += " " + l;
    if (!r.empty()) s += " " + r;
    return s;
}

int main() {
    {
        // 1 -> (A=2, B=3); A's right invalidly points to sibling B (same row, to its right)
        TreeNode* B = new TreeNode(3);
        TreeNode* A = new TreeNode(2, nullptr, B);
        TreeNode* root = new TreeNode(1, A, B);
        Solution sol;
        TreeNode* fixed = sol.correctBinaryTree(root);
        cout << preorder(fixed) << "\n";
    }
    {
        // 1 -> (A=2,B=3); A -> (C=4,D=5); C's right invalidly points to D (same row)
        TreeNode* D = new TreeNode(5);
        TreeNode* C = new TreeNode(4, nullptr, D);
        TreeNode* A = new TreeNode(2, C, D);
        TreeNode* B = new TreeNode(3);
        TreeNode* root = new TreeNode(1, A, B);
        Solution sol;
        TreeNode* fixed = sol.correctBinaryTree(root);
        cout << preorder(fixed) << "\n";
    }
    {
        // 7 -> (A=8,B=9); A's right invalidly points to sibling B (same row)
        TreeNode* B = new TreeNode(9);
        TreeNode* A = new TreeNode(8, nullptr, B);
        TreeNode* root = new TreeNode(7, A, B);
        Solution sol;
        TreeNode* fixed = sol.correctBinaryTree(root);
        cout << preorder(fixed) << "\n";
    }

    return 0;
}
