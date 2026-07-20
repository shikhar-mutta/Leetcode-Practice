// Link: https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/

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

// TC: O(n log n) where n is the number of nodes in the tree
// SC: O(n) where n is the number of nodes in the tree
// Approach:
// 1. Perform a depth-first search (DFS) on the binary tree to calculate the size of each subtree and check if it is a perfect subtree.
// 2. A perfect subtree is defined as a subtree where the left and right subtrees have the same size and are both perfect subtrees themselves
// 3. Store the sizes of all perfect subtrees in a vector.
// 4. Sort the vector of perfect subtree sizes in non-decreasing order.
// 5. Iterate through the sorted vector from the largest size to the smallest size and return the k-th largest perfect subtree size. If there are fewer than k perfect subtrees, return -1
class Solution
{
    vector<int> tree_size;
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        if (l == r && l >= 0)
        {
            tree_size.push_back(l + r + 1);
            return l + r + 1;
        }
        return -1;
    }

public:
    int kthLargestPerfectSubtree(TreeNode *root, int k)
    {
        dfs(root);
        sort(tree_size.begin(), tree_size.end());
        // cout<<tree_size.size()<<endl;

        for (int i = tree_size.size() - 1; i >= 0; i--)
        {
            if ((tree_size.size() - 1 - i) + 1 == k)
                return tree_size[i];
        }
        return -1;
    }
};