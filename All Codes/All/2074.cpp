// Link: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

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

// TC: O(n), SC: O(n)
class Solution
{
public:
    // TC: O(n), SC: O(n)
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        vector<int> vals;
        for (ListNode *p = head; p; p = p->next)
            vals.push_back(p->val);

        int n = vals.size();
        for (int i = 0, group = 1; i < n; group++)
        {
            int len = min(group, n - i); // actual length of the last group may be short
            if (len % 2 == 0)
                reverse(vals.begin() + i, vals.begin() + i + len);
            i += len;
        }

        int j = 0;
        for (ListNode *p = head; p; p = p->next)
            p->val = vals[j++];
        return head;
    }
};
