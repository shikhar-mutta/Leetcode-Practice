// Link: https://leetcode.com/problems/binary-search-tree-iterator-ii/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    vector<int> vals;
    int idx = -1;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        vals.push_back(node->val);
        inorder(node->right);
    }

    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    bool hasNext() {
        return idx + 1 < (int)vals.size();
    }

    int next() {
        idx++;
        return vals[idx];
    }

    bool hasPrev() {
        return idx - 1 >= 0;
    }

    int prev() {
        idx--;
        return vals[idx];
    }
};
