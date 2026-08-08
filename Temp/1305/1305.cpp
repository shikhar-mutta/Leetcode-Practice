// Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& out) {
        if (!root) return;
        inorder(root->left, out);
        out.push_back(root->val);
        inorder(root->right, out);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);
        vector<int> res;
        merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
        return res;
    }
};
