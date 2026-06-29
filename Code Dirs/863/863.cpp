// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TC: O(N) + O(N) + O(N) ~ O(N). SC: O(N) + O(N) + O(N) ~ O(N). N = number of nodes in the tree.
class Solution
{
public:
    void createparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            if (it->left)
            {
                parent[it->left] = it;
                q.push(it->left);
            }
            if (it->right)
            {
                parent[it->right] = it;
                q.push(it->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_map<TreeNode *, bool> vis;
        int dis = 0;
        queue<TreeNode *> q;
        vector<int> ans;
        createparent(root, parent);
        q.push(target);
        vis[target] = true;
        while (!q.empty())
        {
            int sz = q.size();
            if (dis == k)
                break;
            dis++;
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (parent[node] && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans.push_back(it->val);
        }
        return ans;
    }
};