// Link: https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            if (fast->next == nullptr)
                break;
            fast = fast->next;
        }
        return slow;
    }
};
