// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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

// TC: O(n) - where n is the number of nodes in the binary tree. We visit each node once to determine the minimum depth.
// SC: O(n) - In the worst case, the queue will contain all the nodes at the deepest level of the binary tree, which can be up to n/2 nodes in a complete binary tree. Therefore, the space complexity is O(n) in the worst case.
// Approach:
// 1. If the root is null, return 0 as the minimum depth.
// 2. Initialize a queue and push the root node into it. Also, initialize a variable depth to keep track of the current depth level.
// 3. While the queue is not empty, do the following:
//    a. Get the number of nodes at the current depth level (size of the queue).
//    b. For each node at the current depth level, do the following:
//       i. Pop the node from the queue.
//       ii. If the node is a leaf node (both left and right children are null), return the current depth as the minimum depth.
//       iii. If the node has a left child, push it into the queue.
//       iv. If the node has a right child, push it into the queue.
//    c. Increment the depth variable to move to the next depth level.

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                // First leaf node found gives minimum depth
                if (node->left == nullptr && node->right == nullptr)
                    return depth;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};