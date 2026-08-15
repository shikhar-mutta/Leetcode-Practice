// Link: https://leetcode.com/problems/rotate-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n)  SC: O(1)
// Approach: find length and tail, link tail to head to form a ring, break the ring at the new head position
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next) { tail = tail->next; len++; }
        k %= len;
        if (k == 0) return head;
        tail->next = head;
        int stepsToNewTail = len - k;
        ListNode *newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) newTail = newTail->next;
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
