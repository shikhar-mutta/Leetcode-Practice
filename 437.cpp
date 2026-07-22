// Link: https://leetcode.com/problems/path-sum-iii/description/

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
    // TC: O(n), SC: O(n)
    //  Approach:
    //   1. Use a depth-first search (DFS) traversal of the binary tree.
    //   2. Maintain a running sum of the values from the root to the current node.
    //   3. Use a hash map to store the count of prefix sums encountered so far.
    //   4. For each node, check if there exists a prefix sum such that the difference between the current running sum and the prefix sum equals the target sum.
    //   5. If such a prefix sum exists, increment the count of valid paths.
    //   6. After processing the current node, recursively call the DFS function for the left and right children of the current node.
    //   7. Backtrack by decrementing the count of the current running sum in the hash map before returning to the parent node.
    //   8. Return the total count of valid paths found in the binary tree.
    unordered_map<long long, int> prefixCount;
    int count = 0;

    int pathSum(TreeNode *root, int targetSum)
    {
        prefixCount[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }

    void dfs(TreeNode *node, long long curSum, int targetSum)
    {
        if (!node)
            return;
        curSum += node->val;
        auto it = prefixCount.find(curSum - targetSum);
        if (it != prefixCount.end())
            count += it->second;
        prefixCount[curSum]++;
        dfs(node->left, curSum, targetSum);
        dfs(node->right, curSum, targetSum);
        prefixCount[curSum]--;
    }
};
