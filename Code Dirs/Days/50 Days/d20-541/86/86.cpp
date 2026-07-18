// Link: https://leetcode.com/problems/partition-list/description/

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lessHead = new ListNode(0);    // head of less
        ListNode *greaterHead = new ListNode(0); // head of greater
        ListNode *less = lessHead;               // iterator for less
        ListNode *greater = greaterHead;         // iterator for greater

        while (head)
        {
            if (head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;        // Important to avoid cycle
        less->next = greaterHead->next; // Connect the two partitions

        return lessHead->next; // Return the head of the new list
    }
};
