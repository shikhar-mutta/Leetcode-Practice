// Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

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
    // TC: O(n), SC: O(1)
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int first = -1, last = -1, prevIdx = -1;
        int minDist = INT_MAX, i = 1;

        ListNode *prev = head, *cur = head->next;
        while (cur && cur->next) {
            // local maxima or minima w.r.t. both neighbours
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {
                if (first == -1) first = i;
                if (prevIdx != -1)
                    minDist = min(minDist, i - prevIdx);
                prevIdx = i;
                last = i;
            }
            prev = cur;
            cur = cur->next;
            i++;
        }

        if (first == last) // fewer than two critical points
            return {-1, -1};
        return {minDist, last - first};
    }
};
