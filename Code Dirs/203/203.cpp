// Link: https://leetcode.com/problems/remove-linked-list-elements/description/

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
    // TC: O(n). SC: O(1).
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *temp = dummy, *delN;
        while (temp && temp->next)
        {
            if (temp->next->val == val)
            {
                delN = temp->next;
                temp->next = delN->next;
                delete delN;
            }
            else
                temp = temp->next;
        }
        return dummy->next;
    }
};
