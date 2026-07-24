// Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

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

// TC: O(n), SC: O(h) where h is the height of the tree
//   Approach:
// Zigzag path is defined as a sequence of nodes where each node is a child of the previous node, and the direction alternates between left and right at each step. The length of a zigzag path is the number of edges in the path.
//   1. We perform a depth-first search (DFS) traversal of the binary tree. For each node, we calculate the length of the longest zigzag path starting from that node in both left and right directions.
//   2. We maintain a variable best to keep track of the maximum length of any zigzag path found during the traversal.
//   3. For each node, we recursively calculate the lengths of the longest zigzag paths starting from its left and right children. The length of the zigzag path going left from the current node is equal to the length of the zigzag path going right from its left child plus one, and vice versa for the right child.
//   4. We update the best variable with the maximum length found so far.
class Solution
{
public:
    int longestZigZag(TreeNode *root)
    {
        best = 0;
        dfs(root);
        return best;
    }

private:
    int best;
    // returns {length going left from node, length going right from node}
    pair<int, int> dfs(TreeNode *node)
    {
        if (!node)
            return {-1, -1};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int goLeft = l.second + 1; // from left child, then go right
        int goRight = r.first + 1; // from right child, then go left
        best = max(best, max(goLeft, goRight));
        return {goLeft, goRight};
    }
};