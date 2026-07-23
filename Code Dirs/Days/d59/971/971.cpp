// Link: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/

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

//TC: O(n), SC: O(n)
// Approach: DFS
//1. We will do a DFS traversal of the tree and check if the current node's value matches the current value in the voyage vector.
//2. If it doesn't match, we will return false.
//3. If it matches, we will increment the index and check if the left child exists and if its value matches the next value in the voyage vector.
//4. If it doesn't match, we will flip the left and right children of the current node and add the current node's value to the result vector.
//5. We will continue the DFS traversal for the left and right children of the current node.
//6. If we reach the end of the voyage vector and all nodes have been visited, we will return true. Otherwise, we will return false.
//7. Finally, we will return the result vector if the DFS traversal was successful, or a vector containing -1 if it was not successful.
class Solution
{
    int idx = 0;

    bool dfs(TreeNode *node, vector<int> &voyage, vector<int> &result)
    {
        if (!node)
            return true;
        if (node->val != voyage[idx])
            return false;
        idx++;
        if (node->left && idx < (int)voyage.size() && node->left->val != voyage[idx])
        {
            result.push_back(node->val);
            swap(node->left, node->right);
        }
        return dfs(node->left, voyage, result) && dfs(node->right, voyage, result);
    }

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> result;
        if (!dfs(root, voyage, result))
            return {-1};
        return result;
    }
};
