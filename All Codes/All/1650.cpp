// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* a = p;
        Node* b = q;
        while (a != b) {
            a = a ? a->parent : q;
            b = b ? b->parent : p;
        }
        return a;
    }
};
