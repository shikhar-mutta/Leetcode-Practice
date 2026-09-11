// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1, head), *pre = dummy;
        while (true)
        {
            ListNode *check = pre; // To check if there are k nodes left to reverse
            for (int i = 0; i < k; i++)
            {
                check = check->next;
                if (!check)
                    return dummy->next;
            }

            ListNode *cur = pre->next; // point to the first node of the k-group to be reversed
            for (int i = 0; i < k - 1; i++)
            {
                ListNode *nxt = cur->next; // take next node
                cur->next = nxt->next;     // remove nxt from its current position
                nxt->next = pre->next;     // put at the front of the k-group
                pre->next = nxt;           // insert nxt at the front of the k-group
            }
            pre = cur; // move pre to the end of the reversed k-group
        }
    }
};
