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
    // TC: O(n), SC: O(n)
    int pairSum(ListNode *head) {
        vector<int> v;
        for (ListNode *p = head; p; p = p->next)
            v.push_back(p->val);

        int n = v.size(), best = 0;
        for (int i = 0; i < n / 2; i++) // node i pairs with node n-1-i
            best = max(best, v[i] + v[n - 1 - i]);
        return best;
    }
};
