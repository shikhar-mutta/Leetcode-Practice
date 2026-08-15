// Link: https://leetcode.com/problems/insertion-sort-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n^2)  SC: O(1)
// Approach: build a sorted list from scratch, removing each node from the input and inserting it
// into its correct position via a dummy head + scan
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            ListNode *p = &dummy;
            while (p->next && p->next->val < cur->val) p = p->next;
            cur->next = p->next;
            p->next = cur;
            cur = next;
        }
        return dummy.next;
    }
};
