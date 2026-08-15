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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> positions;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int idx = 1;
        while (cur->next) {
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {
                positions.push_back(idx);
            }
            prev = cur;
            cur = cur->next;
            idx++;
        }
        if (positions.size() < 2) return {-1, -1};
        int minDist = INT_MAX;
        for (int i = 1; i < (int)positions.size(); i++) minDist = min(minDist, positions[i] - positions[i-1]);
        int maxDist = positions.back() - positions.front();
        return {minDist, maxDist};
    }
};
