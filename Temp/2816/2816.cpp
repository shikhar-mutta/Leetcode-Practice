// Link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

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
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5) head = new ListNode(0, head);
        for (ListNode* cur = head; cur; cur = cur->next) {
            cur->val = (cur->val * 2) % 10;
            if (cur->next && cur->next->val >= 5) cur->val++;
        }
        return head;
    }
};
