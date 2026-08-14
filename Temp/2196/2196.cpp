// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> hasParent;
        auto getNode = [&](int v) -> TreeNode* {
            if (!nodes.count(v)) nodes[v] = new TreeNode(v);
            return nodes[v];
        };
        for (auto& d : descriptions) {
            TreeNode* p = getNode(d[0]);
            TreeNode* c = getNode(d[1]);
            if (d[2] == 1) p->left = c;
            else p->right = c;
            hasParent.insert(d[1]);
        }
        for (auto& [v, node] : nodes) {
            if (!hasParent.count(v)) return node;
        }
        return nullptr;
    }
};
