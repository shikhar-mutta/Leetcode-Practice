// Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(N log k)  SC: O(k)
// Approach: min-heap of the current head of each list; repeatedly pop the smallest, push its successor
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto l : lists) if (l) pq.push(l);
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (!pq.empty()) {
            ListNode *node = pq.top(); pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) pq.push(node->next);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
