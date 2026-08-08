// Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
public:
    unordered_set<int> vals;

    FindElements(TreeNode* root) {
        recover(root, 0);
    }

    void recover(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        vals.insert(val);
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }

    bool find(int target) {
        return vals.count(target) > 0;
    }
};
