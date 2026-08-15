// Link: https://leetcode.com/problems/merge-in-between-linked-lists/description/

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
    // TC: O(n + m), SC: O(1)
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *before = list1;
        for (int i = 0; i < a - 1; i++) // node just before index a
            before = before->next;
        ListNode *after = before;
        for (int i = 0; i < b - a + 2; i++) // node just after index b
            after = after->next;

        before->next = list2;
        ListNode *tail = list2;
        while (tail->next)
            tail = tail->next;
        tail->next = after;
        return list1;
    }
};
