// Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach:
//   1. We can use two pointers to iterate through both arrays.
//   2. We can initialize two pointers i and j to 0.
//   3. We can iterate through both arrays until we reach the end of either array.
//   4. If nums1[i] is greater than nums2[j], we can increment i. Otherwise, we can calculate the distance j - i and update the result if it is greater than the current result. We can then increment j.
//   5. Finally, we can return the result.
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0, res = 0;
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                ++i;
            }
            else
            {
                res = max(res, j - i);
                ++j;
            }
        }
        return res;
    }
};