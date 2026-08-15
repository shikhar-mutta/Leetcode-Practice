// Link: https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        while (cur) {
            for (int i = 1; i < m && cur; i++) cur = cur->next;
            if (!cur) break;
            ListNode* del = cur->next;
            for (int i = 0; i < n && del; i++) del = del->next;
            cur->next = del;
            cur = cur->next;
        }
        return head;
    }
};
