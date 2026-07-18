// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        // Each stack entry: (node to assign children to, lo, hi, whether it's a left child)
        // We use a tuple: (node*, lo, hi, isLeft)
        int lo = 0, hi = (int)nums.size() - 1;    // Avoid overflow
        int mid = lo + (hi - lo) / 2;             // Avoid overflow
        TreeNode *root = new TreeNode(nums[mid]); // Create the root node

        // stack entries: {node, lo, hi, isLeft}
        stack<tuple<TreeNode *, int, int, bool>> st; // Use tuple for better readability
        st.push({root, lo, mid - 1, true});          // Left child range
        st.push({root, mid + 1, hi, false});         // Right child range

        while (!st.empty())
        {
            auto [parent, l, h, isLeft] = st.top(); // Unpack the top of the stack
            st.pop();                               // Pop the current entry

            if (l > h)
            {
                if (isLeft) // No node to create, set the corresponding child to nullptr
                    parent->left = nullptr;
                else // No node to create, set the corresponding child to nullptr
                    parent->right = nullptr;
                continue; // Skip to the next iteration if the range is invalid
            }

            int m = l + (h - l) / 2;                // Avoid overflow
            TreeNode *node = new TreeNode(nums[m]); // Create a new node for the current range

            if (isLeft) // Attach the new node as the left child of the parent
                parent->left = node;
            else // Attach the new node as the right child of the parent
                parent->right = node;

            st.push({node, l, m - 1, true});  // Push the left child range onto the stack
            st.push({node, m + 1, h, false}); // Push the right child range onto the stack
        }

        return root;
    }
};
