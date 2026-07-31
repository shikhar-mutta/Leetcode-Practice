// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: prefix sums + monotonic increasing deque of indices. For
//  each new prefix index i, pop from the front while prefix[i]-prefix[front]
//  >= k (records the shortest valid subarray ending here); pop from the
//  back while prefix[back] >= prefix[i] (those indices are now useless
//  since a later, smaller prefix is strictly better as a left endpoint).
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int ans = n + 1;
        for (int i = 0; i <= n; i++)
        {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
            {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[dq.back()] >= prefix[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return (ans == n + 1) ? -1 : ans;
    }
};