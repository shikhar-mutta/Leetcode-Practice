// Link: https://leetcode.com/problems/equal-tree-partition/description/

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

// TC: O(n) SC: O(n)
// Approach: compute total sum; collect every subtree sum (excluding the whole tree itself) into a multiset; answer is true iff total/2 is present among subtree sums (and total is even).
class Solution {
    vector<int> sums;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int s = node->val + dfs(node->left) + dfs(node->right);
        sums.push_back(s);
        return s;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int total = dfs(root);
        if (total % 2 != 0) return false;
        int target = total / 2;
        int count = 0;
        for (int s : sums) if (s == target) count++;
        if (target == 0) return count >= 2;
        return count >= 1;
    }
};
