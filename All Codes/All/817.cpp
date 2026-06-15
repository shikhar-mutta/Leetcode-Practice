// Link: https://leetcode.com/problems/linked-list-components/description/

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
    // Use bitset to test that val exists in nums or not
    // TC: O(n + m). SC: O(m) , where m is the size of nums
    int numComponents(ListNode *head, vector<int> &nums)
    {
        bitset<10001> exists;
        for (int i = 0; i < nums.size(); i++)
            exists.set(nums[i]);
        if (head->next == nullptr)
        {
            if (exists.test(head->val))
                return 1;
            return 0;
        }
        ListNode *ptr = head;
        int cnt = 0;
        while (ptr != nullptr)
        {
            bool flag = false;
            while (ptr != nullptr && exists.test(ptr->val))
            {
                flag = true;
                ptr = ptr->next;
            }
            if (flag)
                cnt++;
            if (ptr != nullptr)
                ptr = ptr->next;
        }
        return cnt;
    }
};