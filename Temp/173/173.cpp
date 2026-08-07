// Link: https://leetcode.com/problems/binary-search-tree-iterator/description/

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

// TC: O(1) amortized per next()/hasNext(), O(h) space  SC: O(h)
// Approach: explicit stack simulating inorder traversal — push all left children down to the leftmost node,
// each next() pops one and pushes its right subtree's left spine
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node) {
        while (node) { st.push(node); node = node->left; }
    }
};
