// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long total = 0;
    long long best = 0;

    long long subtreeSum(TreeNode* node) {
        if (!node) return 0;
        long long sum = node->val + subtreeSum(node->left) + subtreeSum(node->right);
        long long other = total - sum;
        best = max(best, sum * other);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        function<long long(TreeNode*)> sumAll = [&](TreeNode* node) -> long long {
            if (!node) return 0;
            return node->val + sumAll(node->left) + sumAll(node->right);
        };
        total = sumAll(root);
        subtreeSum(root);
        return (int)(best % MOD);
    }
};
