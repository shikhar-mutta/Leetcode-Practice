// Link: https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    // TC: O(n+m). SC: O(1).
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        ListNode *temp1 = list1, *temp2 = list2;
        while (temp1 && temp2)
        {
            if (temp1->val > temp2->val)
            {
                curr->next = temp2;
                temp2 = temp2->next;
            }
            else
            {
                curr->next = temp1;
                temp1 = temp1->next;
            }
            curr = curr->next;
        }
        curr->next = temp1 ? temp1 : temp2;

        return dummy->next;
    }
};
