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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur->next) {
            int g = gcd(cur->val, cur->next->val);
            ListNode* node = new ListNode(g, cur->next);
            cur->next = node;
            cur = node->next;
        }
        return head;
    }
};
