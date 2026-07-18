// Link: https://leetcode.com/problems/merge-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;

        // Start merging from the end of nums1 and nums2, and fill nums1 from the end as well.
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are remaining elements in nums2, copy them to nums1 as well.
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        // No need to copy remaining elements from nums1, as they are already in place.
    }
};