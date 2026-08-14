// Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

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
public:
    bool findPath(TreeNode* node, int target, string& path) {
        if (!node) return false;
        if (node->val == target) return true;
        path.push_back('L');
        if (findPath(node->left, target, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(node->right, target, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        int i = 0;
        while (i < (int)startPath.size() && i < (int)destPath.size() && startPath[i] == destPath[i]) i++;
        string res(startPath.size() - i, 'U');
        res += destPath.substr(i);
        return res;
    }
};
