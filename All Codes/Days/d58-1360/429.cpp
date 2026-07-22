// Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    // TC: O(n) where n is the number of nodes in the tree
    // SC: O(n) where n is the number of nodes in the tree
    // Approach:
    //  1. We will use a queue to perform a level order traversal of the n-ary tree.
    //  2. We will push the root node into the queue and then we will keep popping the nodes from the queue and pushing their children into the queue.
    //  3. We will keep track of the number of nodes at each level and we will push the values of the nodes at each level into a vector and then we will push that vector into the answer vector.
    //  4. We will repeat this process until the queue is empty and then we will return the answer vector.
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};
        queue<Node *> q;
        q.push(root);

        vector<vector<int>> ans;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            while (size--)
            {
                Node *node = q.front();
                q.pop();

                level.push_back(node->val);

                for (auto &it : node->children)
                {
                    if (it)
                        q.push(it);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};