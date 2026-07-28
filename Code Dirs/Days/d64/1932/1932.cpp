// Link: https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: index roots by value. Recursively, a leaf whose value matches
// another tree's root gets replaced by that subtree (consuming it). The
// overall root is whichever tree's root value is never referenced as a leaf
// elsewhere. After grafting, validate the result is a proper BST (strict
// in-order increasing) covering every original node exactly once.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> rootByVal;
        unordered_map<int, int> leafRefCount;
        int totalNodes = 0;
        for (auto* t : trees) rootByVal[t->val] = t;
        for (auto* t : trees) {
            function<void(TreeNode*)> countLeaves = [&](TreeNode* node) {
                if (!node) return;
                totalNodes++;
                if (!node->left && !node->right && node != t && rootByVal.count(node->val))
                    leafRefCount[node->val]++;
                countLeaves(node->left);
                countLeaves(node->right);
            };
            countLeaves(t);
        }

        TreeNode* mergedRoot = nullptr;
        int rootCandidates = 0;
        for (auto* t : trees) {
            if (leafRefCount[t->val] == 0) { mergedRoot = t; rootCandidates++; }
        }
        if (rootCandidates != 1) return nullptr;

        unordered_set<int> used;
        function<TreeNode*(TreeNode*)> graft = [&](TreeNode* node) -> TreeNode* {
            if (!node) return nullptr;
            if (!node->left && !node->right && rootByVal.count(node->val) && rootByVal[node->val] != node && !used.count(node->val)) {
                used.insert(node->val);
                return graft(rootByVal[node->val]);
            }
            node->left = graft(node->left);
            node->right = graft(node->right);
            return node;
        };
        TreeNode* result = graft(mergedRoot);

        long long prev = LLONG_MIN;
        int count = 0;
        bool valid = true;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node || !valid) return;
            inorder(node->left);
            if (node->val <= prev) valid = false;
            prev = node->val;
            count++;
            inorder(node->right);
        };
        inorder(result);
        int expectedCount = totalNodes - ((int)trees.size() - 1);
        if (!valid || count != expectedCount) return nullptr;
        return result;
    }
};
