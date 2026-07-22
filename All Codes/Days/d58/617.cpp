// Link: https://leetcode.com/problems/merge-two-binary-trees/description/

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

// TC: O(n), where n is the number of nodes in the smaller tree. In the worst case, we may need to visit all nodes in both trees.
// SC: O(h), where h is the height of the recursion stack. In the worst case, the height of the recursion stack can be equal to the height of the smaller tree, which can be O(n) in the case of a skewed tree. In the average case, the height of the recursion stack will be O(log n) for a balanced tree.
//  Approach:
//   1. We check if either of the input trees is null. If one of them is null, we return the other tree as the merged result.
//   2. If both trees are non-null, we add the values of the current nodes from both trees and store the result in the current node of the first tree.
//   3. We recursively call the mergeTrees function for the left children of both trees and assign the result to the left child of the current node in the first tree.
//   4. We recursively call the mergeTrees function for the right children of both trees and assign the result to the right child of the current node in the first tree.
//   5. Finally, we return the modified first tree as the merged result.
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};