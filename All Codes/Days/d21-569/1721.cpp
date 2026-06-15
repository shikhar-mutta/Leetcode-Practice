// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // TC: O(n), SC: O(1)
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *first = head;
        for (int i = 1; i < k; i++) // kth node from the front
            first = first->next;

        // second trails the end by the same offset -> kth from the back
        ListNode *second = head, *p = first;
        while (p->next) {
            p = p->next;
            second = second->next;
        }

        swap(first->val, second->val);
        return head;
    }
};
