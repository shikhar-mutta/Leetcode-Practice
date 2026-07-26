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

// TC: O(n + q log n) where n = node count, q = queries.size()
// SC: O(n)
// Approach: an in-order traversal of a BST gives all values in sorted
// order, so each query reduces to a binary search on that sorted array:
// the ceiling (min value >= query) via lower_bound, and the floor (max
// value <= query) either equal to an exact match or the element right
// before the ceiling.
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sorted;
        inorder(root, sorted);

        vector<vector<int>> res;
        res.reserve(queries.size());
        for (int q : queries) {
            // ceiling: first element >= q
            auto it = lower_bound(sorted.begin(), sorted.end(), q);
            int mx = (it != sorted.end()) ? *it : -1;

            // floor: largest element <= q
            int mn;
            if (it != sorted.end() && *it == q) {
                mn = q; // exact match: floor equals the value
            } else if (it != sorted.begin()) {
                mn = *prev(it); // element just before the ceiling
            } else {
                mn = -1; // nothing <= q
            }
            res.push_back({mn, mx});
        }
        return res;
    }

private:
    void inorder(TreeNode* node, vector<int>& out) {
        if (!node)
            return;
        inorder(node->left, out);
        out.push_back(node->val);
        inorder(node->right, out);
    }
};
