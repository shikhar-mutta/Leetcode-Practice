// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

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

// TC: O(N) SC: O(H)
//  Approach:
//  1. We can use a recursive approach to solve this problem. We can start from the root of the tree and calculate the total sum of the tree.
//  2. Then we can use another recursive function to calculate the sum of each subtree and calculate the product of the sum of the subtree and the sum of the rest of the tree.
//  3. We can keep track of the maximum product found so far and return it at the end.
class Solution
{
public:
    int maxProduct(TreeNode *root)
    {
        int MOD = 1000000007;
        long long max_val = LLONG_MIN;

        int tot_sum = totalSum(root);

        aux(root, tot_sum, max_val);
        max_val = max_val % MOD;

        return max_val;
    }

private:
    int totalSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    int aux(TreeNode *root, long long tot_sum, long long &max_val)
    {
        if (root == nullptr)
            return 0;

        long long leftSum = aux(root->left, tot_sum, max_val);
        long long rightSum = aux(root->right, tot_sum, max_val);

        max_val = max(leftSum * (tot_sum - leftSum), max_val);
        max_val = max(rightSum * (tot_sum - rightSum), max_val);

        return root->val + leftSum + rightSum;
    }
};