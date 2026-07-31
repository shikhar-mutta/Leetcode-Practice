// Link: https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: We can use a hash map to store the nodes of the trees and their counts. We then find the root of the merged tree by looking for a node that has a count of 1. We then perform a depth-first search (DFS) to validate if the merged tree is a valid binary search tree (BST) and also count the number of merged trees. If the count of merged trees is equal to the total number of trees, we return the root of the merged tree; otherwise, we return nullptr.
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        TreeNode *nodeMap[50001] = {nullptr};
        int count[50001] = {0};

        for (TreeNode *t : trees)
        {
            nodeMap[t->val] = t;
            count[t->val]++;
            if (t->left)
                count[t->left->val]++;
            if (t->right)
                count[t->right->val]++;
        }

        TreeNode *globalRoot = nullptr;
        for (TreeNode *t : trees)
        {
            if (count[t->val] == 1)
            {
                globalRoot = t;
                break;
            }
        }

        if (!globalRoot)
            return nullptr;

        nodeMap[globalRoot->val] = nullptr;
        int mergedCount = 1;

        if (isValidBST(globalRoot, INT_MIN, INT_MAX, nodeMap, mergedCount) &&
            mergedCount == trees.size())
        {
            return globalRoot;
        }

        return nullptr;
    }

private:
    bool isValidBST(TreeNode *node, int minVal, int maxVal, TreeNode **nodeMap,
                    int &mergedCount)
    {
        if (!node)
            return true;

        if (nodeMap[node->val])
        {
            TreeNode *graftTemplate = nodeMap[node->val];
            nodeMap[node->val] = nullptr;
            mergedCount++;

            node->left = graftTemplate->left;
            node->right = graftTemplate->right;
        }

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return isValidBST(node->left, minVal, node->val, nodeMap,
                          mergedCount) &&
               isValidBST(node->right, node->val, maxVal, nodeMap, mergedCount);
    }
};