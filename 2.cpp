// Link: https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int rem = 0, sum, v1, v2;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy; // tail always points to last node
        while (l1 || l2 || rem)
        {
            v1 = l1 ? l1->val : 0;
            v2 = l2 ? l2->val : 0;
            sum = v1 + v2 + rem;
            rem = sum / 10;
            tail->next = new ListNode(sum % 10); // append to tail, not dummy
            tail = tail->next;                   // advance tail
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
