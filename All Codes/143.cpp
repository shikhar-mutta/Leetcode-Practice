// Link: https://leetcode.com/problems/reorder-list/description/

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
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head != NULL)
            head = head->next, len++;
        return len;
    }
    void reorderList(ListNode *head)
    {
        int listLength = getLength(head);
        if (listLength <= 2)
            return;
        ListNode *mid = head;
        for (int i = 0; i < (listLength - 1) / 2; i++)
            mid = mid->next;
        ListNode *secondHead = mid->next;
        mid->next = NULL;
        // reverse the second half of the list
        ListNode *prev = NULL, *curr = secondHead, *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        secondHead = prev; // pre is new head of the second half of the list

        // merge the two halves
        ListNode *first = head, *second = secondHead;
        while (first != NULL && second != NULL)
        {
            ListNode *nextFirst = first->next, *nextSecond = second->next;
            first->next = second;     // Insert second after first
            second->next = nextFirst; // Insert nextFirst after second
            first = nextFirst;        // Move to the next node in the first half
            second = nextSecond;      // Move to the next node in the second half
        }
    }
};