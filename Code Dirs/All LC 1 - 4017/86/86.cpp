// Link: https://leetcode.com/problems/partition-list/description/

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
// Approach: build two chains (less-than-x, greater-or-equal-x) preserving relative order, then splice together
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), geDummy(0);
        ListNode *lessTail = &lessDummy, *geTail = &geDummy;
        for (ListNode *cur = head; cur; cur = cur->next) {
            if (cur->val < x) { lessTail->next = cur; lessTail = cur; }
            else { geTail->next = cur; geTail = cur; }
        }
        geTail->next = nullptr;
        lessTail->next = geDummy.next;
        return lessDummy.next;
    }
};
