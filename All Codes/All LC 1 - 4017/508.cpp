// Link: https://leetcode.com/problems/most-frequent-subtree-sum/description/

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

// TC: O(n) where n is the number of nodes in the tree
// SC: O(n) where n is the number of nodes in the tree
// Approach:
//   1. Use a recursive function to calculate the sum of each subtree.
//   2. Store the frequency of each subtree sum in a hash map.
//   3. Keep track of the maximum frequency of any subtree sum.
//   4. After traversing the entire tree, iterate through the hash map to find all subtree sums that have the maximum frequency and store them in a result vector.
//   5. Return the result vector containing the most frequent subtree sums.
class Solution
{
public:
    int solve(TreeNode *root, unordered_map<int, int> &mp, int &maxi)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int ls = solve(root->left, mp, maxi);
        int rs = solve(root->right, mp, maxi);
        int currsum = root->val + ls + rs;
        mp[currsum]++;
        maxi = max(maxi, mp[currsum]);
        return currsum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> mp;
        int maxi = 0;
        solve(root, mp, maxi);
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second == maxi)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};