// Link: https://leetcode.com/problems/linked-list-cycle/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        if (fast == nullptr || fast->next == nullptr)
            return false;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
