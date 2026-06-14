// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) // Find the middle of the linked list
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
            prev->next = nullptr; //IMP: Split the list into two halves

        TreeNode *root = new TreeNode(slow->val);  // slow is mid point
        root->left = sortedListToBST(head);        // Split Left half
        root->right = sortedListToBST(slow->next); // Split Right half

        return root;
    }
};