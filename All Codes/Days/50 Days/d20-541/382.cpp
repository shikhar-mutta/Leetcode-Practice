// Link: https://leetcode.com/problems/linked-list-random-node/description/

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
    ListNode *head;

public:
    // Initialize with head of linked list
    Solution(ListNode *head) : head(head) {}

    // Reservoir sampling: pick node i with prob 1/i → uniform over all nodes
    int getRandom()
    {
        int res = head->val, i = 2;
        for (ListNode *cur = head->next; cur; cur = cur->next, i++)
            if (rand() % i == 0)
                res = cur->val;
        return res;
    }
};
