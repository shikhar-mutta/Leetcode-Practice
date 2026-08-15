// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(1)  SC: O(1)
// Approach: since we can't access the head, copy the next node's value into this node and skip past it,
// effectively "becoming" that node and deleting the real next node instead
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
