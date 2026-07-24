// Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input array.
    // SC: O(n) where n is the size of the input array.
    // Approach:
    //  1. We will use two deques to keep track of the minimum and maximum elements in the current window.
    //  2. We will iterate through the array and for each element, we will add it to the deques and check if the difference between the maximum and minimum elements in the current window is less than or equal to the limit.
    //  3. If the difference is greater than the limit, we will remove elements from the left of the window until the difference is less than or equal to the limit.
    //  4. We will keep track of the maximum length of the window that satisfies the condition and return it at the end.
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> minq;
        deque<int> maxq;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int maxi = 0;
        while (left < n && right < n)
        {
            if (minq.empty())
            {
                minq.push_back(right);
            }
            else
            {
                while (!minq.empty() && nums[minq.back()] >= nums[right])
                {
                    minq.pop_back();
                }
                minq.push_back(right);
            }

            if (maxq.empty())
            {
                maxq.push_back(right);
            }
            else
            {
                while (!maxq.empty() && nums[maxq.back()] <= nums[right])
                {
                    maxq.pop_back();
                }
                maxq.push_back(right);
            }

            int cost = nums[maxq.front()] - nums[minq.front()];
            while (cost > limit)
            {
                if (maxq.front() == left)
                {
                    maxq.pop_front();
                }
                if (minq.front() == left)
                {
                    minq.pop_front();
                }
                left++;
                cost = nums[maxq.front()] - nums[minq.front()];
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};