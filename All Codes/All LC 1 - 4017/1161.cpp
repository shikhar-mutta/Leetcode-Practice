// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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

// TC: O(n) where n is the number of nodes in the binary tree
// SC: O(n) for the queue used in BFS
//   Approach:
//    1. Use a level-order traversal (BFS) to traverse the binary tree level by level.
//    2. For each level, calculate the sum of node values and keep track of the maximum sum and the corresponding level.
//    3. Return the level with the maximum sum after traversing all levels of the tree.
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        vector<pair<int, int>> arr;
        q.push(root);
        int l = 0;
        while (!q.empty())
        {
            l++;
            int s = q.size();
            int sum = 0;
            for (int i = 0; i < s; i++)
            {
                TreeNode *a = q.front();
                q.pop();
                if (a->left)
                    q.push(a->left);
                if (a->right)
                    q.push(a->right);
                sum += a->val;
            }
            arr.push_back({sum, l});
        }
        int ans = 0;
        int maxi = INT_MIN;
        for (auto p : arr)
        {
            if (p.first > maxi)
            {
                maxi = p.first;
                ans = p.second;
            }
        }
        return ans;
    }
};