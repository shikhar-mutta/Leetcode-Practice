// Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    // TC: O(N log k). SC: O(k)
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        ListNode *dummy = new ListNode(-1); // Dummy node to simplify edge cases
        ListNode *temp = dummy;             // Pointer to build the merged list
        // Min-heap to store the current nodes of each list
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        // Push to the heap
        for (auto &it : lists)
            if (it)
                pq.push({it->val, it});

        while (!pq.empty()) // Until heap is not empty
        {
            ListNode *node = pq.top().second;
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if (node->next) // if next node exist then push them to the heap
                pq.push({node->next->val, node->next});
        }
        return dummy->next;
    }

    // // TC: O(N * k). SC: O(1)
    // ListNode *merge(ListNode *lists1, ListNode *lists2)
    // {
    //     ListNode *dummy = new ListNode(0);
    //     ListNode *curr = dummy;

    //     while (lists1 && lists2)
    //     {
    //         if (lists1->val < lists2->val)
    //             curr->next = lists1, lists1 = lists1->next;
    //         else
    //             curr->next = lists2, lists2 = lists2->next;
    //         curr = curr->next;
    //     }

    //     curr->next = lists1 ? lists1 : lists2;
    //     return dummy->next;
    // }

    // ListNode *mergeKLists(vector<ListNode *> &lists)
    // {
    //     if (lists.empty())
    //         return nullptr;

    //     ListNode *result = lists[0];
    //     for (int i = 1; i < lists.size(); i++)
    //         result = merge(result, lists[i]);
    //     return result;
    // }
};