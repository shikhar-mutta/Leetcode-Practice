// Link: https://leetcode.com/problems/path-sum-iii/description/

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
// Approach: DFS carrying running prefix sum, use a hashmap of prefix-sum
// counts seen on the current root-to-node path to count valid paths ending here
class Solution {
    unordered_map<long long, int> prefixCount;

    int dfs(TreeNode* node, long long sum, int target) {
        if (!node) return 0;
        sum += node->val;
        int count = prefixCount[sum - target];

        prefixCount[sum]++;
        count += dfs(node->left, sum, target);
        count += dfs(node->right, sum, target);
        prefixCount[sum]--;

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixCount[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
