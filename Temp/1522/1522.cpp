// Link: https://leetcode.com/problems/diameter-of-n-ary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
public:
    int best = 0;

    int height(Node* node) {
        if (!node) return 0;
        int max1 = 0, max2 = 0;
        for (Node* child : node->children) {
            int h = height(child);
            if (h > max1) { max2 = max1; max1 = h; }
            else if (h > max2) max2 = h;
        }
        best = max(best, max1 + max2);
        return max1 + 1;
    }

    int diameter(Node* root) {
        height(root);
        return best;
    }
};
