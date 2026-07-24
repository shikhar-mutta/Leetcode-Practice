// Link: https://leetcode.com/problems/validate-binary-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //    Approach:
    //    1. We first check the indegree of each node. If any node has an indegree greater than 1, it means that the node has more than one parent, which is not allowed in a valid binary tree. We also keep track of the root node, which should be the only node with an indegree of 0. If there is more than one node with an indegree of 0, or if there is no node with an indegree of 0, then the tree is not valid.
    //    2. After identifying the root node, we perform a depth-first search (DFS) or breadth-first search (BFS) traversal starting from the root node. We keep track of the number of nodes we have seen during the traversal. If we have seen all n nodes by the end of the traversal, then the tree is valid. If we have not seen all n nodes, it means that there are disconnected components in the graph, and the tree is not valid.
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                                 vector<int> &rightChild)
    {
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int c : {leftChild[i], rightChild[i]})
            {
                if (c != -1 && ++indeg[c] > 1)
                    return false;
            }
        }
        int root = -1;
        for (int i = 0; i < n; ++i)
        {
            if (indeg[i] == 0)
            {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        if (root == -1)
            return false;

        int seen = 0;
        stack<int> st;
        st.push(root);
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            ++seen;
            for (int c : {leftChild[u], rightChild[u]})
                if (c != -1)
                    st.push(c);
        }
        return seen == n;
    }
};