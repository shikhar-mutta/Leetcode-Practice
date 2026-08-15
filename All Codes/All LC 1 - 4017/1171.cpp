// Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // TC: O(n), SC: O(n)
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        unordered_map<int, ListNode *> mp;

        int sum = 0;
        // Pass 1: record the LAST node reaching each prefix sum.
        for (ListNode *cur = dummy; cur; cur = cur->next)
            sum += cur->val, mp[sum] = cur;

        // Pass 2: jump over every sublist between equal prefix sums.
        sum = 0;
        for (ListNode *cur = dummy; cur; cur = cur->next)
            sum += cur->val, cur->next = mp[sum]->next;

        return dummy->next;
    }
};