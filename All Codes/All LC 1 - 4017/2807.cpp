// Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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
    // TC: O(n log V), SC: O(1)
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        for (ListNode *p = head; p && p->next;) {
            int g = __gcd(p->val, p->next->val);
            p->next = new ListNode(g, p->next);
            p = p->next->next; // skip past the inserted node
        }
        return head;
    }
};
