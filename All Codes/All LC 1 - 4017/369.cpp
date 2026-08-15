// Link: https://leetcode.com/problems/plus-one-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n)  SC: O(1) extra (O(n) recursion stack)
// Approach: recurse to the tail, add 1 and propagate carry back up; if the
// head still has carry, prepend a new node
class Solution {
    int addOne(ListNode* node) {
        if (!node) return 1;
        int carry = addOne(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }

public:
    ListNode* plusOne(ListNode* head) {
        int carry = addOne(head);
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};
