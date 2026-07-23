// Link: https://leetcode.com/problems/all-possible-full-binary-trees/description/

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

// TC: O(2^n), SC: O(n)
//  Approach:
//  1. Use memoization to store the results of previously computed values of n.
//  2. If n is already computed, return the stored result.
//  3. If n is 1, return a vector containing a single node tree
//  4. If n is even, return an empty vector as full binary trees can only have an odd number of nodes.
//  5. For each odd number l from 1 to n-2, compute the number of nodes in the right subtree as r = n - 1 - l. Recursively compute the left and right subtrees for l and r, respectively
//  6. For each combination of left and right subtrees, create a new tree with a root node and the left and right subtrees, and add it to the result vector.
//  7. Store the result in the memoization map and return it.
//  8. The time complexity is O(2^n) because for each node, we can have two choices (left or right), and the space complexity is O(n) due to the recursion stack.
class Solution
{
public:
    unordered_map<int, vector<TreeNode *>> memo;

    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (memo.count(n))
            return memo[n];
        vector<TreeNode *> result;
        if (n == 1)
        {
            result.push_back(new TreeNode(0));
            return memo[n] = result;
        }
        if (n % 2 == 0)
            return memo[n] = result;

        for (int l = 1; l <= n - 2; l += 2)
        {
            int r = n - 1 - l;
            auto leftList = allPossibleFBT(l);
            auto rightList = allPossibleFBT(r);
            for (auto left : leftList)
                for (auto right : rightList)
                    result.push_back(new TreeNode(0, left, right));
        }
        return memo[n] = result;
    }
};
