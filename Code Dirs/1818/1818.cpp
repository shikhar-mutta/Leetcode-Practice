// Link: https://leetcode.com/problems/minimum-absolute-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the length of the array
    // SC: O(n) as we are using a vector to store the sorted version of nums1 for binary searching
    //  Approach:
    //   1. Create a sorted version of nums1 for binary searching
    //   2. Iterate through the elements of nums1 and nums2, calculating the absolute difference between the corresponding elements
    //   3. For each element, check if we can find a better match in the sorted version of nums1 using binary search
    //   4. If we find a better match, calculate the potential saving and update the maximum saving
    //   5. Finally, return the original sum of absolute differences minus the maximum saving
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();

        // Create the sorted version of nums1 for binary searching
        vector<int> sortedn1 = nums1;
        sort(sortedn1.begin(), sortedn1.end());

        long long curDiffSum = 0;
        int maxSaving = 0;

        for (int i = 0; i < n; i++)
        {
            int origDiff = abs(nums1[i] - nums2[i]);
            curDiffSum += origDiff;

            // Optimization: Only search if we can potentially beat our best saving
            if (origDiff > maxSaving)
            {
                auto it = lower_bound(sortedn1.begin(), sortedn1.end(), nums2[i]);

                // Check the element greater than or equal to nums2[i]
                if (it != sortedn1.end())
                {
                    int newDiff = abs(*it - nums2[i]);
                    maxSaving = max(maxSaving, origDiff - newDiff);
                }

                // Check the element just smaller than nums2[i]
                if (it != sortedn1.begin())
                {
                    int newDiff = abs(*(it - 1) - nums2[i]);
                    maxSaving = max(maxSaving, origDiff - newDiff);
                }
            }
        }

        // The final sum is the original sum minus our best single improvement
        return (curDiffSum - maxSaving) % 1000000007;
    }
};