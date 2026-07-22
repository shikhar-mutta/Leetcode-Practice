// Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

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
    // TC: O(n), where n is the number of nodes in the N-ary tree. We visit each node exactly once during the traversal.
    // SC: O(h), where h is the height of the N-ary tree.
    // Approach:
    //   1. We define a recursive function A that takes a node r as input.
    //   2. If r is not null, we iterate through its children and recursively call A on each child.
    //   3. After visiting all children, we add the value of the current node r to the result vector a.
    //   4. Finally, we return the result vector a containing the postorder traversal of the N-ary tree.
    vector<int> postorder(Node *r)
    {
        vector<int> a;
        function<void(Node *)> A = [&](Node *r)
        {
            if (r)
            {
                for (Node *p : r->children)
                    A(p);
                a.push_back(r->val);
            }
        };
        return A(r), a;
    }
};