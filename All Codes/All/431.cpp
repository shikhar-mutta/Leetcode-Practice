// Link: https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/description/

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

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// TC: O(n)  SC: O(n)
// Approach: left-child/right-sibling encoding - binary left = first n-ary
// child, binary right = next n-ary sibling
class Codec {
public:
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        if (!root->children.empty()) {
            node->left = encode(root->children[0]);
            TreeNode* cur = node->left;
            for (int i = 1; i < (int)root->children.size(); i++) {
                cur->right = encode(root->children[i]);
                cur = cur->right;
            }
        }
        return node;
    }

    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        Node* node = new Node(root->val);
        TreeNode* child = root->left;
        while (child) {
            node->children.push_back(decode(child));
            child = child->right;
        }
        return node;
    }
};
