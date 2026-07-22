// Link: https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of nodes in the quad tree.
    // SC: O(h), where h is the height of the quad tree.
    //  Approach:
    // 1. If either of the nodes is a leaf node, we can return the other node if it is not a leaf node, or return the current node if it is a leaf node with value 1.
    // 2. If both nodes are not leaf nodes, we recursively call the intersect function on their children (topLeft, topRight, bottomLeft, bottomRight).
    // 3. After getting the results from the recursive calls, we check if all four children are leaf nodes and have the same value. If they do, we can merge them into a single leaf node with that value.
    // 4. If not, we create a new node with the four children and return it.
    // 5. This process continues until we reach the root of the quad tree, at which point we return the final result.
    Node *intersect(Node *q1, Node *q2)
    {
        if (q1->isLeaf)
            return q1->val ? q1 : q2;
        if (q2->isLeaf)
            return q2->val ? q2 : q1;
        Node *tl = intersect(q1->topLeft, q2->topLeft);
        Node *tr = intersect(q1->topRight, q2->topRight);
        Node *bl = intersect(q1->bottomLeft, q2->bottomLeft);
        Node *br = intersect(q1->bottomRight, q2->bottomRight);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
        {
            return new Node(tl->val, true);
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};
