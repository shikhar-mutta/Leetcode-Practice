// Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

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

// TC: O(n) SC: O(h) where h is the height of the tree
// Approach:
//   1. We will do a post order traversal of the tree and for each node, we will keep track of the number of leaf nodes at each distance from the current node.
//   2. We will use an array of size distance + 1 to keep track of the number of leaf nodes at each distance from the current node.
//   3. For each node, we will calculate the number of good leaf node pairs by multiplying the number of leaf nodes at each distance from the left subtree with the number of leaf nodes at each distance from the right subtree and adding it to the count of good leaf node pairs.
//   4. We will return the array of size distance + 1 to the parent node so that it can calculate the number of good leaf node pairs for its own subtree.
class Solution
{
public:
    int countPairs(TreeNode *root, int distance)
    {
        int count = 0;
        solve(root, distance, count);
        return count;
    }

private:
    array<int, 11> solve(TreeNode *root, int distance, int &count)
    {
        array<int, 11> freq = {};
        if (!root)
        {
            return freq;
        }
        if (!root->left && !root->right)
        {
            freq[0] = 1;
            return freq;
        }
        array<int, 11> freqLeft = solve(root->left, distance, count);
        array<int, 11> freqRight = solve(root->right, distance, count);
        int total = 0;
        for (int i = distance - 2; i >= 0; i--)
        {
            total += freqRight[distance - 2 - i];
            count += freqLeft[i] * total;
        }
        for (int i = 1; i <= 10; i++)
        {
            freq[i] = freqLeft[i - 1] + freqRight[i - 1];
        }
        return freq;
    }
};
