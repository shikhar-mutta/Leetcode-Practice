// Link: https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/

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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> byRoot;
        unordered_map<int, int> leafCount;
        for (auto* t : trees) byRoot[t->val] = t;

        for (auto* t : trees) {
            if (t->left && !t->left->left && !t->left->right) leafCount[t->left->val]++;
            if (t->right && !t->right->left && !t->right->right) leafCount[t->right->val]++;
        }

        // find candidate root: value not equal to any leaf, i.e. its root wasn't consumed as a leaf target multiple times
        TreeNode* root = nullptr;
        int candidates = 0;
        for (auto* t : trees) {
            if (leafCount[t->val] == 0) {
                root = t;
                candidates++;
            } else if (leafCount[t->val] > 1) {
                return nullptr;
            }
        }
        if (candidates != 1) return nullptr;

        int usedCount = 0;
        unordered_set<int> used;

        function<bool(TreeNode*)> attach = [&](TreeNode* node) -> bool {
            if (!node) return true;
            if (!node->left && !node->right && byRoot.count(node->val) && !used.count(node->val)) {
                if (used.count(node->val)) return false;
                if (byRoot[node->val] != node) {
                    // don't attach a tree to itself as its own leaf-copy accidentally
                    node->left = byRoot[node->val]->left;
                    node->right = byRoot[node->val]->right;
                    used.insert(node->val);
                    usedCount++;
                }
            }
            return attach(node->left) && attach(node->right);
        };

        used.insert(root->val);
        usedCount++;
        attach(root);

        if (usedCount != (int)trees.size()) return nullptr;

        // validate BST via in-order
        bool valid = true;
        long long prev = LLONG_MIN;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node || !valid) return;
            inorder(node->left);
            if (node->val <= prev) valid = false;
            prev = node->val;
            inorder(node->right);
        };
        inorder(root);

        return valid ? root : nullptr;
    }
};
