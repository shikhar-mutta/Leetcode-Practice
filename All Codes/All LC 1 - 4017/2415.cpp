// Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

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

// TC: O(n)
// SC: O(h), h = tree height (recursion depth)
// Approach: since this is a perfect binary tree, walk left and right
// subtrees in lockstep from the root's two children - at each recursive
// step, "leftChild" and "rightChild" are always mirror-image positions at
// the same depth. Swap their values whenever that depth is even (0-indexed
// from root's children, meaning the ACTUAL tree level, 1-indexed, is odd),
// then recurse into the mirrored pairs (left.left with right.right, and
// left.right with right.left) to continue swapping deeper odd levels.
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        DFS(root->left, root->right, 0);
        return root;
    }

private:
    void DFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild == nullptr || rightChild == nullptr) {
            return;
        }
        if (level % 2 == 0) {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }
        DFS(leftChild->left, rightChild->right, level + 1);
        DFS(leftChild->right, rightChild->left, level + 1);
    }
};
