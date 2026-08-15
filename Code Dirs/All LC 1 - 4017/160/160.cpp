// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// TC: O(n+m)  SC: O(1)
// Approach: two pointers each walk their own list then switch to the other list's head; they meet at the
// intersection (or both reach null together) after at most 2*max(n,m) steps since combined distance matches
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
