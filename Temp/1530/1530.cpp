// Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int count = 0;
    int distance;

    vector<int> dfs(TreeNode* node) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};

        vector<int> leftDepths = dfs(node->left);
        vector<int> rightDepths = dfs(node->right);

        for (int l : leftDepths) {
            for (int r : rightDepths) {
                if (l + r <= distance) count++;
            }
        }

        vector<int> res;
        for (int l : leftDepths) if (l + 1 <= distance) res.push_back(l + 1);
        for (int r : rightDepths) if (r + 1 <= distance) res.push_back(r + 1);
        return res;
    }

    int countPairs(TreeNode* root, int distance) {
        this->distance = distance;
        dfs(root);
        return count;
    }
};
