// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int val = 0;
        while (head) {
            val = val * 2 + head->val;
            head = head->next;
        }
        return val;
    }
};
