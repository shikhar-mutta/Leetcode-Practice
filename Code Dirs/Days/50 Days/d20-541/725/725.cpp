// Link: https://leetcode.com/problems/split-linked-list-in-parts/description/

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
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
            length++, head = head->next;
        return length;
    }
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int length = getLength(head);
        int partSize = length / k, extraNodes = length % k;
        vector<ListNode *> parts(k, nullptr);
        ListNode *curr = head;
        for (int i = 0; i < k && curr; i++) // curr not null
        {
            parts[i] = curr;
            int thisPartSize = partSize + (i < extraNodes ? 1 : 0);
            for (int j = 0; j < thisPartSize - 1; j++)
                curr = curr->next;
            ListNode *next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return parts;
    }
};