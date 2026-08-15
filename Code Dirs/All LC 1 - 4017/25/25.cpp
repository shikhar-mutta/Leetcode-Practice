// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
// Approach: check next k nodes exist, reverse them in place, recurse on the rest, splice results together
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return head;
            node = node->next;
        }
        ListNode *prev = reverseKGroup(node, k);
        ListNode *cur = head;
        for (int i = 0; i < k; i++) {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
