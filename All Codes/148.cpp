// Link: https://leetcode.com/problems/sort-list/description/

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
    // TC: O(nlogn) | SC: O(1)

    // Merge two sorted linked lists
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
                tail->next = l1, l1 = l1->next;
            else
                tail->next = l2, l2 = l2->next;
            tail = tail->next;
        }
        // Append the remaining nodes of l1 or l2
        tail->next = l1 ? l1 : l2;
        // Return Dummy next as the head of the merged list
        return dummy.next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        // Find mid point of the list using slow and fast pointers
        while (fast && fast->next)
        {
            prev = slow; // Just before the mid point
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // Split the list into two halves

        // Divide
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        // Conquer
        return merge(l1, l2);
    }

    // // TC: O(nlogn) | SC: O(n)
    // ListNode *sortList(ListNode *head)
    // {
    //     if (!head || !head->next)
    //         return head;

    //     ListNode *temp = head;
    //     vector<int> lists;
    //     while (temp)
    //         lists.push_back(temp->val), temp = temp->next;

    //     sort(lists.begin(), lists.end());
    //     temp = head;
    //     int i = 0;
    //     while (temp)
    //         temp->val = lists[i++], temp = temp->next;
    //     return head;
    // }
};
