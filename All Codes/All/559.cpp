// Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

#include <bits/stdc++.h>
using namespace std;

// class Node {
// public:
//     int val;
//     vector<Node*> children;
//     Node() {}
//     Node(int _val) { val = _val; }
//     Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
// };

class Solution
{
public:
    // TC: O(n) where n is the number of nodes in the tree
    // SC: O(n) for the queue
    // Approach: BFS
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        queue<Node *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            int sz = q.size();
            depth++;
            while (sz--)
            {
                Node *cur = q.front();
                q.pop();
                for (Node *child : cur->children)
                    if (child)
                        q.push(child);
            }
        }
        return depth;
    }
};