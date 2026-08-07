// Link: https://leetcode.com/problems/odd-even-linked-list/description/

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
// Approach: split into odd-index and even-index chains in place, then
// attach the even chain after the odd chain
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
