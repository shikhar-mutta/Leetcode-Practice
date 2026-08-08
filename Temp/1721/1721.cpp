// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; i++) first = first->next;
        ListNode* second = head;
        ListNode* runner = first;
        while (runner->next) { runner = runner->next; second = second->next; }
        swap(first->val, second->val);
        return head;
    }
};
