// Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

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
    // TC: O(n + m), SC: O(m)
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        bitset<100001> st;
        for (int num : nums)
            st[num] = true;
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next)
        {
            if (st[cur->next->val])
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};