// Link: https://leetcode.com/problems/maximum-size-of-a-set-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) for the two sorts
// SC: O(1) extra (sorts in place)
// Approach: sort both arrays, count distinct values in each (count1/count2)
// and the distinct values common to both (cntunq) via a two-pointer merge.
// Each array keeps n/2 elements, so take up to n/2 of each array's exclusive
// values (count - cntunq, capped at n/2), then add the shared values, which
// can always be covered by whichever array has leftover capacity. Cap the
// total at n since the final set can't exceed the kept element count.
class Solution
{
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int count1 = 1;
        int count2 = 1;
        for (int i = 1; i < nums1.size(); i++)
        {
            if (nums1[i - 1] < nums1[i])
            {
                count1++;
            }
        }
        for (int i = 1; i < nums2.size(); i++)
        {
            if (nums2[i - 1] < nums2[i])
            {
                count2++;
            }
        }
        int i = 0;
        int j = 0;
        int cntunq = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                cntunq++;
                int val = nums1[i];
                while (i < n && nums1[i] == val)
                    i++;
                while (j < n && nums2[j] == val)
                    j++;
            }
        }
        int set1 = min(count1 - cntunq, n / 2);
        int set2 = min(count2 - cntunq, n / 2);
        return min(n, set1 + set2 + cntunq);
    }
};