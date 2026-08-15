// Link: https://leetcode.com/problems/reverse-linked-list-ii/description/

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
// Approach: walk to node before left, then repeatedly move the node right after it to the front of the sublist
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        for (int i = 1; i < left; i++) prev = prev->next;
        ListNode *cur = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode *moved = cur->next;
            cur->next = moved->next;
            moved->next = prev->next;
            prev->next = moved;
        }
        return dummy.next;
    }
};
