// Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

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

// Added
// TC: O(n)  SC: O(depth)
// Approach: scan the string tracking each node's depth (dash count)
// and value. Maintain a stack of nodes by depth; when a new node's
// depth matches stack.size(), it's the left child of the node currently
// at the top; otherwise pop back to the correct ancestor and attach as
// its right child (since preorder always visits left subtree fully
// before right, a depth <= current stack size means we've returned to
// attach a right child).
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> stack_;
        int n = traversal.size();
        int i = 0;
        while (i < n) {
            int depth = 0;
            while (traversal[i] == '-') { depth++; i++; }
            int j = i;
            while (j < n && isdigit(traversal[j])) j++;
            int val = stoi(traversal.substr(i, j - i));
            i = j;

            TreeNode* node = new TreeNode(val);
            while ((int)stack_.size() > depth) stack_.pop_back();
            if (!stack_.empty()) {
                if (!stack_.back()->left) stack_.back()->left = node;
                else stack_.back()->right = node;
            }
            stack_.push_back(node);
        }
        return stack_.empty() ? nullptr : stack_[0];
    }
};
