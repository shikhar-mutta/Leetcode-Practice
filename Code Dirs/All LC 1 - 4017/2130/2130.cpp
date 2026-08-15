// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

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
    int pairSum(ListNode* head) {
        vector<int> vals;
        for (ListNode* p = head; p; p = p->next) vals.push_back(p->val);
        int n = vals.size();
        int best = 0;
        for (int i = 0; i < n / 2; i++) best = max(best, vals[i] + vals[n - 1 - i]);
        return best;
    }
};
