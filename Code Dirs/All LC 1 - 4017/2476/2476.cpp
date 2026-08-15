// Link: https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/

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
    void inorder(TreeNode* node, vector<int> &vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> vals;
        inorder(root, vals);

        vector<vector<int>> ans;
        for (int q : queries) {
            auto it = lower_bound(vals.begin(), vals.end(), q);
            int ceilVal = -1, floorVal = -1;
            if (it != vals.end()) {
                if (*it == q) { ceilVal = floorVal = *it; ans.push_back({floorVal, ceilVal}); continue; }
                ceilVal = *it;
            }
            if (it != vals.begin()) floorVal = *prev(it);
            ans.push_back({floorVal, ceilVal});
        }
        return ans;
    }
};
