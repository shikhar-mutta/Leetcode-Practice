// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // TC: O(h+k). SC: O(h) for recursion stack.
    int kthSmallest(TreeNode *root, int k)
    {
        // Inorder traversal of a BST visits values in ascending order;
        // stop at the kth one.
        int ans = -1;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (--k == 0)
            {
                ans = cur->val;
                break;
            }
            cur = cur->right;
        }
        return ans;
    }
};
