// Link: https://leetcode.com/problems/add-two-numbers-ii/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n+m)  SC: O(n+m)
// Approach: push digits onto stacks, pop and add with carry, prepend
// results to build the answer list in correct order
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (ListNode* n = l1; n; n = n->next) s1.push(n->val);
        for (ListNode* n = l2; n; n = n->next) s2.push(n->val);

        ListNode* head = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) { sum += s1.top(); s1.pop(); }
            if (!s2.empty()) { sum += s2.top(); s2.pop(); }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        return head;
    }
};
