// Link: https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        k = k % len;
        if (k == 0)
            return head;
        ListNode *dummy = new ListNode(-1, head), *fast = dummy, *slow = dummy;
        for (int i = 0; i < k; i++)
            fast = fast->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = dummy->next;
        dummy->next = slow->next;
        slow->next = nullptr;
        return dummy->next;
    }
};