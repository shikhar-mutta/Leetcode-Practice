// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

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
    // TC: O(n). SC: O(1).
    int getDecimalValue(ListNode *head)
    {
        int num = 0;
        while (head)
            num = num * 2 + head->val, head = head->next;
        return num;
    }
};
