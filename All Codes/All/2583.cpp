// Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

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

// TC: O(n) + O(nlogk) ~ O(nlogk)
// SC: O(n)
// Approach:
// 1. We will do a level order traversal of the tree and store the sum of each level in a vector.
// 2. Then we will use nth_element to find the kth largest element in the vector.
// 3. If k is greater than the size of the vector, we will return -1.
class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        vector<long long> sum;
        q.push(root);
        while (!q.empty())
        {
            long long levelsum = 0;
            int size = q.size();
            while (size--)
            {
                TreeNode *node = q.front();
                levelsum += node->val;
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            sum.push_back(levelsum);
        }
        if (k > sum.size())
            return -1;
        nth_element(sum.begin(), sum.begin() + (sum.size() - k), sum.end());
        return sum[sum.size() - k];
    }
};