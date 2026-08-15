// Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        unordered_map<int, ListNode*> lastNode;
        int sum = 0;
        lastNode[0] = &dummy;
        for (ListNode* cur = head; cur; cur = cur->next) {
            sum += cur->val;
            lastNode[sum] = cur;
        }
        sum = 0;
        for (ListNode* cur = &dummy; cur; cur = cur->next) {
            sum += cur->val;
            cur->next = lastNode[sum]->next;
        }
        return dummy.next;
    }
};
