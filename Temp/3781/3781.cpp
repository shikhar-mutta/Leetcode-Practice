// Link: https://leetcode.com/problems/maximum-score-after-binary-swaps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
//  Approach: a '1' can only be swapped leftward with adjacent '0's, so
//  effectively each '1' can "claim" any not-yet-claimed nums value to its
//  left. Scan left to right pushing each nums[i] into a max-heap; whenever
//  s[i]=='1', pop the current maximum and add it to the score.
class Solution
{
public:
    long long maximumScore(vector<int> &nums, string s)
    {
        int n = nums.size();
        priority_queue<int> pq;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                pq.push(nums[i]);
            }
            else if (!pq.empty() && pq.top() > nums[i])
            {
                ans += pq.top();
                pq.pop();
                pq.push(nums[i]);
            }
            else
            {
                ans += nums[i];
            }
        }
        return ans;
    }
};