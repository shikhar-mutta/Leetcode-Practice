// Link: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevTail = &dummy;
        ListNode* cur = head;
        int groupLen = 1;
        while (cur) {
            ListNode* node = cur;
            int count = 1;
            while (count < groupLen && node->next) { node = node->next; count++; }
            ListNode* nextGroupStart = node->next;
            if (count % 2 == 0) {
                ListNode* prev = nextGroupStart;
                ListNode* c = cur;
                while (c != nextGroupStart) {
                    ListNode* nxt = c->next;
                    c->next = prev;
                    prev = c;
                    c = nxt;
                }
                prevTail->next = prev;
                prevTail = cur;
            } else {
                prevTail = node;
            }
            cur = nextGroupStart;
            groupLen++;
        }
        return dummy.next;
    }
};
