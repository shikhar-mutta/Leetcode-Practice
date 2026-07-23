// Link: https://leetcode.com/problems/leaf-similar-trees/description/

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

// TC: O(n) SC: O(h) where n is the number of nodes in the tree and h is the height of the tree
// Approach:
//  1. We define a helper function collectLeaves that takes a TreeNode and a vector of integers as input. This function performs a depth-first traversal of the tree and collects the values of the leaf nodes in the vector.
//  2. In the leafSimilar function, we create two vectors leaves1 and leaves2 to store the leaf values of the two trees.
//  3. We call collectLeaves on both root1 and root2 to populate leaves1 and leaves2.
//  4. Finally, we compare the two vectors and return true if they are equal, indicating that the two trees are leaf-similar, and false otherwise.
class Solution
{
public:
    void collectLeaves(TreeNode *node, vector<int> &leaves)
    {
        if (!node)
            return;
        if (!node->left && !node->right)
        {
            leaves.push_back(node->val);
            return;
        }
        collectLeaves(node->left, leaves);
        collectLeaves(node->right, leaves);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaves1, leaves2;
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};
