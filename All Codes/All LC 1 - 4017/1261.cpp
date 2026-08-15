// Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n) where n is the number of nodes in the tree
// SC: O(n) for the bitset to store the values of the nodes in the tree
//    Approach:
//     1. We will use a bitset to store the values of the nodes in the tree. The size of the bitset will be 2^21, which is the maximum number of nodes in the tree. We will use the value of the node as the index in the bitset. If the value of the node is present in the tree, we will set the corresponding index in the bitset to 1. Otherwise, we will set it to 0.
//     2. We will use a depth-first search (DFS) to traverse the tree and set the values of the nodes in the bitset. We will start from the root node and set its value to 0. Then, we will recursively set the values of the left and right children of the node. The value of the left child will be 2 * x + 1, and the value of the right child will be 2 * x + 2, where x is the value of the current node.
//     3. To find if a value is present in the tree, we will simply check if the corresponding index in the bitset is set to 1. If it is, we will return true. Otherwise, we will return false.

bitset<1048576> hasX = 0; // 2097152=2**21
class FindElements
{
public:
    TreeNode *root;

    FindElements(TreeNode *root) { dfs(root, 0); }
    ~FindElements() { hasX = 0; }
    void dfs(TreeNode *root, int x)
    {
        if (!root)
            return;
        root->val = x;
        hasX[x] = 1;
        dfs(root->left, 2 * x + 1);
        dfs(root->right, 2 * x + 2);
    }

    bool find(int target) { return hasX[target]; }
};
