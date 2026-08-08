// Link: https://leetcode.com/problems/split-linked-list-in-parts/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n+k) SC: O(1) extra (result pointers only)
// Approach: compute length; base size = len/k, extra = len%k (first `extra` parts get one more node); walk the list cutting off each part.
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for (ListNode* cur = head; cur; cur = cur->next) len++;
        int base = len / k, extra = len % k;
        vector<ListNode*> res(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (!cur) break;
            res[i] = cur;
            int size = base + (i < extra ? 1 : 0);
            for (int j = 0; j < size-1; j++) cur = cur->next;
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return res;
    }
};
