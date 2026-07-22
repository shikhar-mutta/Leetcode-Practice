// Link: https://leetcode.com/problems/maximum-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n^2), SC: O(n) for recursion stack
// Approach:
//  1. The maximum binary tree is constructed by recursively finding the maximum element in the current subarray and making it the root of the tree.
//  2. The left subtree is constructed from the elements to the left of the maximum element, and the right subtree is constructed from the elements to the right of the maximum element.
//  3. The base case for the recursion is when the left index is greater than the right index, in which case we return NULL.
//  4. The recursion continues until the entire array has been processed, and the final tree is returned as the result.
class Solution
{
public:
    TreeNode *solve(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int idx = l;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] > nums[idx])
            {
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(nums[idx]);

        root->left = solve(nums, l, idx - 1);
        root->right = solve(nums, idx + 1, r);

        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, 0, nums.size() - 1);
    }
};