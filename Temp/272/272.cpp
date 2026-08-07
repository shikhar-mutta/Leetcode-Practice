// Link: https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/

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

// TC: O(n)  SC: O(n)
// Approach: inorder traversal collects values in sorted order, then a sliding window of size k
// over the sorted array finds the contiguous window minimizing max distance to target
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> sorted;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            sorted.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        int left = 0, right = sorted.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target - sorted[mid] > sorted[mid + k] - target) left = mid + 1;
            else right = mid;
        }
        return vector<int>(sorted.begin() + left, sorted.begin() + left + k);
    }
};
