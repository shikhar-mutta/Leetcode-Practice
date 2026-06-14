// Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head), *temp = dummy->next;
        int tm;
        while (temp && temp->next)
        {
            tm = temp->val;
            temp->val = temp->next->val;
            temp->next->val = tm;
            temp = temp->next->next;
        }
        return head;
    }
};
