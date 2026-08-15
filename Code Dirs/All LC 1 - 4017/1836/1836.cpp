// Link: https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/description/

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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> count;
        for (ListNode* node = head; node; node = node->next) count[node->val]++;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;
        while (cur) {
            if (count[cur->val] > 1) {
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
