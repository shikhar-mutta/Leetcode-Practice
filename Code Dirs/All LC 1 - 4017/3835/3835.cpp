// Link: https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: for a fixed left end, cost is non-decreasing as the right
// end extends (both max-min and length grow), and for a fixed right end,
// cost is non-increasing as the left end advances — so the valid window
// boundary moves monotonically. Two pointers with monotonic deques
// tracking the window max and min let us shrink from the left in O(1)
// amortized per step, counting r-l+1 valid subarrays ending at each r.
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        deque<int> maxD, minD;
        long long ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            while (!maxD.empty() && nums[maxD.back()] <= nums[r])
                maxD.pop_back();
            maxD.push_back(r);
            while (!minD.empty() && nums[minD.back()] >= nums[r])
                minD.pop_back();
            minD.push_back(r);

            while ((long long)(nums[maxD.front()] - nums[minD.front()]) * (r - l + 1) > k)
            {
                if (maxD.front() == l)
                    maxD.pop_front();
                if (minD.front() == l)
                    minD.pop_front();
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
