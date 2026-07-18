// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // dummy node before head so we can handle removing head (n == list length)
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;

        // advance fast n+1 steps so the gap between fast and slow is n+1
        // when fast reaches null, slow is exactly at the node BEFORE the target
        for (int i = 0; i <= n; i++)
            fast = fast->next;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to delete
        ListNode *del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy.next; // head may have changed if we deleted the original head
    }
};
