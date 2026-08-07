// Link: https://leetcode.com/problems/sort-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n log n)  SC: O(log n) recursion
// Approach: merge sort — split at the middle (slow/fast), recursively sort each half, merge
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (left && right) {
            if (left->val <= right->val) { tail->next = left; left = left->next; }
            else { tail->next = right; right = right->next; }
            tail = tail->next;
        }
        tail->next = left ? left : right;
        return dummy.next;
    }
};
