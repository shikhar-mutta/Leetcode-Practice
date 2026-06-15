// Link: https://leetcode.com/problems/next-greater-node-in-linked-list/description/

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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> nums;
        while (head)
            nums.push_back(head->val), head = head->next;

        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> st(n, -1);
        int top = -1;
        for (int i = 0; i < n; i++)
        {
            while (top != -1 && nums[i] > nums[st[top]])
                ans[st[top]] = nums[i], top--;
            st[++top] = i;
        }
        return ans;
    }
};