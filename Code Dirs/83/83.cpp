// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    // TC: O(N). SC: O(1).
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *Dummy = new ListNode(-1, head);
        ListNode *temp = Dummy->next, *delN;
        if (!temp)
            return head;
        while (temp->next)
        {
            if (temp->next->val == temp->val)
            {
                delN = temp->next;
                temp->next = delN->next;
                delete delN;
            }
            else
            {
                temp = temp->next;
            }
        }
        return Dummy->next;
    }
};
