// Link: https://leetcode.com/problems/binary-tree-cameras/description/

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
    int cameras = 0;
    // 0 = not covered, 1 = covered no camera, 2 = has camera
    int dfs(TreeNode* node) {
        if (!node) return 1;
        int l = dfs(node->left);
        int r = dfs(node->right);
        if (l == 0 || r == 0) {
            cameras++;
            return 2;
        }
        if (l == 2 || r == 2) return 1;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};
