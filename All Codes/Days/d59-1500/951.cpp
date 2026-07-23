// Link: https://leetcode.com/problems/flip-equivalent-binary-trees/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n), where n is the number of nodes in the tree.
// SC: O(h), where h is the height of the tree.
// Approach:
// 1. We will check if both trees are null, if yes then return true.
// 2. If one of the trees is null or the values of the nodes are not equal, then return false.
// 3. We will check if the left child of the first tree is equal to the left child of the second tree and the right child of the first tree is equal to the right child of the second tree or if the left child of the first tree is equal to the right child of the second tree and the right child of the first tree is equal to the left child of the second tree.
// 4. If any of the above conditions are true, then return true, else return false.
// 5. Finally, we will return the result of the above conditions.
class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2 || root1->val != root2->val)
            return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
