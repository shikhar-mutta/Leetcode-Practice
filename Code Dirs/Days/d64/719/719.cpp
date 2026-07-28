// Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n + n log(maxDiff))  SC: O(1)
// Approach: sort nums, then binary search on the distance value d;
// count how many pairs have distance <= d using a sliding window
// (two-pointer) in O(n), and find the smallest d whose count >= k.
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = nums[n - 1] - nums[0];
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            long long count = 0;
            int left = 0;
            for (int right = 0; right < n; right++)
            {
                while (nums[right] - nums[left] > mid)
                    left++;
                count += right - left;
            }
            if (count >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
