// Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    // TC: O(n), SC: O(1)  (reuses the zero-delimiter nodes)
    ListNode *mergeNodes(ListNode *head) {
        ListNode *write = head; // reuse the leading 0 node as the first sum slot
        ListNode *p = head->next;
        int sum = 0;
        while (p) {
            if (p->val == 0) {
                write = write->next;
                write->val = sum;
                sum = 0;
            } else {
                sum += p->val;
            }
            p = p->next;
        }
        write->next = nullptr; // drop the trailing structure past the last sum
        return head->next;
    }
};
