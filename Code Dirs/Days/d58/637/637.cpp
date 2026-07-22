// Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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

// TC: O(N) where N is the number of nodes in the binary tree. We visit each node exactly once.
// SC: O(M) where M is the maximum number of nodes at any level in the binary tree. This is the maximum size of the queue at any point in time.
// Approach:
// 1. We use a queue to perform a level-order traversal of the binary tree.
// 2. For each level, we calculate the sum of the node values and the number of nodes at that level.
// 3. We then compute the average for that level and store it in the result vector.
// 4. Finally, we return the result vector containing the averages of each level.
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            double sum = 0;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(sum / sz);
        }
        return res;
    }
};
