#include <bits/stdc++.h>
using namespace std;
#include "1932.cpp"

string preorder(TreeNode* root) {
    if (!root) return "null";
    string s = to_string(root->val);
    string l = preorder(root->left);
    string r = preorder(root->right);
    return s + " " + l + " " + r;
}

int main() {
    {
        TreeNode* t0 = new TreeNode(2, new TreeNode(1), nullptr);
        TreeNode* t1 = new TreeNode(3, new TreeNode(2), new TreeNode(5));
        TreeNode* t2 = new TreeNode(5, new TreeNode(4), nullptr);
        vector<TreeNode*> trees = {t0, t1, t2};
        Solution sol;
        TreeNode* res = sol.canMerge(trees);
        cout << (res ? preorder(res) : "null") << "\n";
    }
    {
        TreeNode* t0 = new TreeNode(5, new TreeNode(3), new TreeNode(8));
        TreeNode* t1 = new TreeNode(3, new TreeNode(2), new TreeNode(6));
        vector<TreeNode*> trees = {t0, t1};
        Solution sol;
        TreeNode* res = sol.canMerge(trees);
        cout << (res ? preorder(res) : "null") << "\n";
    }
    {
        TreeNode* t0 = new TreeNode(5, new TreeNode(4), nullptr);
        TreeNode* t1 = new TreeNode(3);
        vector<TreeNode*> trees = {t0, t1};
        Solution sol;
        TreeNode* res = sol.canMerge(trees);
        cout << (res ? preorder(res) : "null") << "\n";
    }

    return 0;
}
