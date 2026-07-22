// Link: https://leetcode.com/problems/construct-string-from-binary-tree/description/

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

// TC: O(n), where n is the number of nodes in the binary tree. We visit each node exactly once during the traversal.
// SC: O(h), where h is the height of the binary tree. The space complexity is determined by the maximum depth of the recursion stack, which can be at most h in the worst case (for a skewed tree). In the average case, for a balanced binary tree, the space complexity would be O(log n).
// Approach:
// 1. We perform a pre-order traversal of the binary tree, starting from the root node.
// 2. For each node, we append its value to the result string.
// 3. If the node has a left child, we recursively call the function for the left child and enclose the result in parentheses.
// 4. If the node has a right child, we recursively call the function for the right child and enclose the result in parentheses. If the node has no left child but has a right child, we still need to include an empty pair of parentheses for the left child to maintain the correct structure of the string representation.
// 5. Finally, we return the constructed string representation of the binary tree.
class Solution
{
public:
    void solve(TreeNode *root, string &ans)
    {
        ans += to_string(root->val);
        if (root->left)
        {
            ans.push_back('(');
            solve(root->left, ans);
            ans.push_back(')');
        }
        else if (!root->left && root->right)
        {
            ans.push_back('(');
            ans.push_back(')');
        }
        if (root->right)
        {
            ans.push_back('(');
            solve(root->right, ans);
            ans.push_back(')');
        }
    }
    string tree2str(TreeNode *root)
    {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};