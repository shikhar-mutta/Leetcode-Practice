// Link: https://leetcode.com/problems/insertion-sort-list/description/

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
    // TC: O(n^2). SC: O(1).
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        ListNode *cur = head, *next = nullptr;

        while (cur)
        {
            next = cur->next;
            while (temp->next && temp->next->val < cur->val)
                temp = temp->next;
            cur->next =
                temp->next;   // insert cur into the sorted part of the list
            temp->next = cur; // insert cur into the sorted part of the list
            cur = next;       // move to the next node in the original list
            temp = dummy;     // reset temp to dummy for the next iteration
        }

        return dummy->next;
    }

    // // TC: O(nlogn) + O(n) = O(nlogn). SC: O(n) for storing the values in a vector.
    // ListNode *insertionSortList(ListNode *head)
    // {
    //     vector<int> v;
    //     ListNode *temp = head;
    //     while (temp)
    //         v.push_back(temp->val), temp = temp->next;
    //     sort(v.begin(), v.end());
    //     temp = head;
    //     int i = 0;
    //     while (temp)
    //         temp->val = v[i++], temp = temp->next;
    //     return head;
    // }
};