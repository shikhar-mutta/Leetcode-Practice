// Link: https://leetcode.com/problems/deepest-leaves-sum/description/

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

class Solution
{
public:
    // TC: O(n) SC: O(n) where n is the number of nodes in the tree
    //  Approach:
    //  1. We can use a breadth-first search (BFS) approach to solve this problem. We can use a queue to keep track of the nodes at each level of the tree.
    //  2. We can start by adding the root node to the queue. We can then repeatedly dequeue a node from the queue and add its value to a sum variable. We can also add its left and right children to the queue if they exist. We can continue this process until the queue is empty. At this point, the sum variable will contain the sum of the values of the nodes at the deepest level of the tree.
    //  3. We can return the sum variable as the result.
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            int sz = q.size();
            sum = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return sum;
    }
};