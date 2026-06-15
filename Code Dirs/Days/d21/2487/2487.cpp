// Link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head)
        {
            ListNode *nx = head->next;
            head->next = prev;
            prev = head;
            head = nx;
        }
        return prev;
    }

public:
    // TC: O(n), SC: O(1)  (iterative -> no recursion stack risk)
    ListNode *removeNodes(ListNode *head)
    {
        head = reverse(head);
        // keep only nodes >= running max while scanning right-to-left
        int mx = INT_MIN;
        ListNode dummy(0), *tail = &dummy;
        for (ListNode *p = head; p; p = p->next)
        {
            if (p->val >= mx)
            {
                mx = p->val;
                tail->next = p;
                tail = p;
            }
        }
        tail->next = nullptr;
        return reverse(dummy.next);
    }
};