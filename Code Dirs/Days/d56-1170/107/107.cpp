// Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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

// TC: O(n) - where n is the number of nodes in the binary tree. We visit each node once to determine the level order traversal.
// SC: O(n) - In the worst case, the queue will contain all the nodes at the deepest level of the binary tree, which can be up to n/2 nodes in a complete binary tree. Therefore, the space complexity is O(n) in the worst case.
// Approach:
// 1. If the root is null, return an empty result.
// 2. Initialize a queue and push the root node into it.
// 3. While the queue is not empty, do the following:
//    a. Get the number of nodes at the current level (size of the queue).
//    b. For each node at the current level, do the following:
//       i. Pop the node from the queue.
//       ii. Add the node's value to the current level's result.
//       iii. If the node has a left child, push it into the queue.
//       iv. If the node has a right child, push it into the queue.
//    c. Add the current level's result to the final result.
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            result.push_back(level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
