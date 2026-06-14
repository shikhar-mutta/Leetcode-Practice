// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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

// TC: O(n), SC: O(1)
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head), *prev = dummy, *cur = head;
        while (cur)
        {
            if (cur->next && cur->val == cur->next->val)
            {
                int dupVal = cur->val;
                while (cur && cur->val == dupVal)
                    cur = cur->next;
                prev->next = cur;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
