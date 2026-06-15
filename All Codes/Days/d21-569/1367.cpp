// Link: https://leetcode.com/problems/linked-list-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    bool match(TreeNode *root, ListNode *temp)
    {
        if (temp == NULL) // LL is fully traversed
            return true;
        if (root == NULL || root->val != temp->val) // BT is fully traversed or value mismatch
            return false;
        // If the current nodes match, continue to check the left and right subtrees
        return match(root->left, temp->next) || match(root->right, temp->next);
    }

    bool solve(TreeNode *root, ListNode *head)
    {
        if (root == NULL)
            return false;
        // if one val match then go for next.
        if (root->val == head->val)
        {
            ListNode *temp = head;
            if (match(root->left, temp->next) || match(root->right, temp->next))
                return true;
        }
        // Goto left-right subtrees of the current node
        return solve(root->left, head) || solve(root->right, head);
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        return solve(root, head);
    }
};