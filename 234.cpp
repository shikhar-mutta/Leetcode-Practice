// Link: https://leetcode.com/problems/palindrome-linked-list/description/

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

// TC: O(n) SC: O(1)
class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *curr = head, *pre = nullptr, *temp;
        while (curr)
        {
            temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseLL(slow->next);
        fast = head;
        while (slow)
        {
            if (fast->val == slow->val)
                fast = fast->next, slow = slow->next;
            else
                return false;
        }
        return true;
    }
};
