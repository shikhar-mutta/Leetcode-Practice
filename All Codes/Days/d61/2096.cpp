// Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

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

// TC: O(n)
// SC: O(n)
//  Approach:
//   1. We will use a recursive function to find the path from the root to the startValue and destValue nodes.
//   2. We will store the path in two strings, one for the startValue and one for the destValue.
//   3. We will then compare the two strings and remove the common prefix, which represents the path from the root to the lowest common ancestor (LCA) of the two nodes.
//   4. The remaining characters in the startValue string will be replaced with 'U' to represent moving up to the LCA, and the remaining characters in the destValue string will be reversed to represent moving down to the destValue node
//   5. Finally, we will concatenate the two strings and return the result as the final path from startValue to destValue.
class Solution
{
public:
    bool getPath(TreeNode *root, int target, string &path)
    {

        if (root->val == target)
        {
            return true;
        }

        if (root->left && getPath(root->left, target, path))
        {
            path.push_back('L');
        }
        else if (root->right && getPath(root->right, target, path))
        {
            path.push_back('R');
        }

        return !path.empty();
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {

        string ss = "", sd = "";
        getPath(root, startValue, ss);
        getPath(root, destValue, sd);

        while (!ss.empty() && !sd.empty() && ss.back() == sd.back())
        {
            ss.pop_back();
            sd.pop_back();
        }

        reverse(sd.begin(), sd.end());
        int srcLen = ss.size();
        string startPath(srcLen, 'U');
        return startPath + sd;
    }
};
