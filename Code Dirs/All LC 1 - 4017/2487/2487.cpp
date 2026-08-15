// Link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* reversedHead = prev;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int maxSoFar = 0;
        cur = reversedHead;
        while (cur) {
            if (cur->val >= maxSoFar) {
                maxSoFar = cur->val;
                tail->next = cur;
                tail = cur;
            }
            cur = cur->next;
        }
        tail->next = nullptr;
        ListNode* result = dummy->next;

        prev = nullptr;
        cur = result;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
