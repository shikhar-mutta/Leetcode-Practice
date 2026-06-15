// Link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

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

class Solution
{
public:
    // TC: O(n), SC: O(1)
    ListNode *doubleIt(ListNode *head)
    {
        // A leading digit >= 5 doubles past 9, so it needs a new carry node.
        if (head->val >= 5)
            head = new ListNode(0, head);
        ListNode *node = head;

        while (node)
        {
            node->val = (node->val * 2) % 10;
            if (node->next && node->next->val >= 5)
                node->val++; // carry from the next digit's doubling
            node = node->next;
        }

        return head;
    }
};
