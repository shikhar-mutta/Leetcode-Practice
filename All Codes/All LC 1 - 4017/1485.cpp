// Link: https://leetcode.com/problems/clone-binary-tree-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* random;
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
};

class NodeCopy {
public:
    int val;
    NodeCopy* left;
    NodeCopy* right;
    NodeCopy* random;
    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
};

class Solution {
public:
    unordered_map<Node*, NodeCopy*> mp;

    NodeCopy* dfs(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];
        NodeCopy* copy = new NodeCopy(node->val);
        mp[node] = copy;
        copy->left = dfs(node->left);
        copy->right = dfs(node->right);
        copy->random = dfs(node->random);
        return copy;
    }

    NodeCopy* copyRandomBinaryTree(Node* root) {
        return dfs(root);
    }
};
