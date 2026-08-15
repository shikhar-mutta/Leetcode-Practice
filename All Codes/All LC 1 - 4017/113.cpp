// Link: https://leetcode.com/problems/path-sum-ii/description/

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
    vector<vector<int>> res;
    void call(TreeNode *root, int ts, int curr, vector<int> &vec)
    {
        if (!root)
            return;
        curr += root->val;
        vec.push_back(root->val);
        if (root && !root->left && !root->right)
        {
            if (curr == ts)
                res.push_back(vec);
            vec.pop_back();
            return;
        }
        call(root->left, ts, curr, vec);
        call(root->right, ts, curr, vec);
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int ts)
    {
        vector<int> vec;
        call(root, ts, 0, vec);
        return res;
    }
};