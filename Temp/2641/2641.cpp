// Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> level = {root};
        while (!level.empty()) {
            // gather next level (with original values) and compute its total sum
            vector<TreeNode*> nextLevel;
            int nextLevelSum = 0;
            for (auto node : level) {
                if (node->left) { nextLevel.push_back(node->left); nextLevelSum += node->left->val; }
                if (node->right) { nextLevel.push_back(node->right); nextLevelSum += node->right->val; }
            }

            for (auto node : level) {
                int childrenSum = 0;
                if (node->left) childrenSum += node->left->val;
                if (node->right) childrenSum += node->right->val;
                if (node->left) node->left->val = nextLevelSum - childrenSum;
                if (node->right) node->right->val = nextLevelSum - childrenSum;
            }

            level = nextLevel;
        }
        root->val = 0;
        return root;
    }
};
