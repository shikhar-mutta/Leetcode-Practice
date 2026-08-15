// Link: https://leetcode.com/problems/remove-linked-list-elements/description/

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
// Approach: dummy head + prev pointer, skip any node whose value matches val
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) prev->next = cur->next;
            else prev = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};
