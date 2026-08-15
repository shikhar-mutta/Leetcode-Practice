// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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
    // TC: O(n) and SC: O(1)
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *temp = head, *slow = &dummy; // slow starts before head so it stops one before middle
        while (temp && temp->next)
        {
            temp = temp->next->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = delNode->next;

        return dummy.next;
    }
};
