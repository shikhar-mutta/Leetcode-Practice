// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(len)  SC: O(1)
// Approach: two pointers n+1 apart; when the fast one reaches the end, slow sits just before the node to remove
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i < n + 1; i++) fast = fast->next;
        while (fast) { fast = fast->next; slow = slow->next; }
        ListNode *toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        return dummy.next;
    }
};
