// Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(nlog(max-min))
    // SC: O(1)
    //   Approach:
    //   1. Sort the array in ascending order.
    //   2. Initialize low and high pointers to the minimum and maximum values of the array.
    //   3. Perform a binary search to find the minimum maximum difference.
    //   4. For each mid value, check if it is possible to form p pairs with a maximum difference less than or equal to mid.
    //   5. If it is possible, update the answer and move the high pointer to mid - 1. Otherwise, move the low pointer to mid + 1.
    //   6. Return the answer as the result.
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int high = nums[nums.size() - 1] - nums[0];
        int low = 0;
        int mid;
        int ans = high;
        while (low <= high)
        {
            mid = (low + high) / 2;
            int count = 0;
            int i = 0;
            int j = 1;
            while (count < p && j < nums.size())
            {
                if (nums[j] - nums[i] <= mid)
                {
                    ++count;
                    i += 2;
                    j += 2;
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
            if (count >= p)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};