// Link: https://leetcode.com/problems/reverse-linked-list/description/

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
    // TC: O(n), SC: O(1)
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head, *temp;
        while (cur != nullptr)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
