// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // (col, row, val) tuples, then sort by col, then row, then val.
        vector<array<int, 3>> nodes;
        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *n, int r, int c)
        {
            if (!n)
                return;
            nodes.push_back({c, r, n->val});
            dfs(n->left, r + 1, c - 1);
            dfs(n->right, r + 1, c + 1);
        };
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> res;
        for (size_t i = 0; i < nodes.size(); i++)
        {
            if (i == 0 || nodes[i][0] != nodes[i - 1][0])
                res.push_back({});
            res.back().push_back(nodes[i][2]);
        }
        return res;
    }
};
