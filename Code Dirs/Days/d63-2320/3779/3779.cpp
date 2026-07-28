// Link: https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/description/

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

// TC: O(n)  SC: O(h)
//  Approach: DFS. For each node, return the count of dominant nodes in its subtree and the maximum value in its subtree. A node is dominant if its value is greater than or equal to the maximum value in its subtree. Recursively compute these values for the left and right subtrees, and then combine them to determine the count of dominant nodes and the maximum value for the current node's subtree. Finally, return the count of dominant nodes for the entire tree.
class Solution
{
public:
    pair<int, int> foo(TreeNode *root)
    {
        int count = 0;
        int maxVal = 0;

        if (root->left)
        {
            pair<int, int> a = foo(root->left);
            count += a.first;
            maxVal = max(maxVal, a.second);
        }

        if (root->right)
        {
            pair<int, int> a = foo(root->right);
            count += a.first;
            maxVal = max(maxVal, a.second);
        }

        if (root->val >= maxVal)
        {
            maxVal = root->val;
            count++;
        }

        return {count, maxVal};
    }

    int countDominantNodes(TreeNode *root) { return foo(root).first; }
};