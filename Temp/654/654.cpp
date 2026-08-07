// Link: https://leetcode.com/problems/maximum-binary-tree/description/

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

// TC: O(n^2) worst case SC: O(n)
// Approach: recursively find the max element in the current range, make it root, recurse on left and right subranges.
class Solution {
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int maxIdx = l;
        for (int i = l+1; i <= r; i++) if (nums[i] > nums[maxIdx]) maxIdx = i;
        TreeNode* node = new TreeNode(nums[maxIdx]);
        node->left = build(nums, l, maxIdx-1);
        node->right = build(nums, maxIdx+1, r);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};
