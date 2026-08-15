// Link: https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
};

// TC: O(n) where n = total nodes in both trees  SC: O(n)
// Approach: recursive merge - if either node is a true leaf, result is a
// true leaf; if both are leaves (both false), result is that leaf; else
// recurse on all 4 quadrants and try to collapse if all children agree
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) return quadTree1->val ? quadTree1 : quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val ? quadTree2 : quadTree1;

        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
            return new Node(tl->val, true);
        }
        return new Node(true, false, tl, tr, bl, br);
    }
};
