// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if (n > m) // Ensure nums1 is the smaller array to optimize the binary search
            return findMedianSortedArrays(nums2, nums1);
        // Binary search on the smaller array
        int lo = 0, hi = n;
        // The total number of elements in the combined array is n + m,to find the median position
        int half = (n + m + 1) / 2;

        // try to find position from left 
        while (lo <= hi)
        {
            int cut1 = (lo + hi) / 2; // Number of elements taken from nums1
            int cut2 = half - cut1;   // Number of elements taken from nums2

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1]; // Left element of nums1
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];     // Right element of nums1
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1]; // Left element of nums2
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];     // Right element of nums2

            // Check if we have found the correct partition
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n + m) % 2 == 1)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) // take fewer elements from nums1
            {
                hi = cut1 - 1;
            }
            else // take more elements from nums1
            {
                lo = cut1 + 1;
            }
        }
        return 0.0;
    }
};
