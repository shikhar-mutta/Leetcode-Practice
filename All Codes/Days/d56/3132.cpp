// Link: https://leetcode.com/problems/find-the-integer-added-to-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn)
    // SC: O(1)
    // Approach:
    //  1. Sort both the arrays.
    //  2. Iterate through the first array and for each element, calculate the difference between the first element of the second array and the current element of the first array.
    //  3. Check if adding this difference to the current element of the first array results in all elements of the second array. If yes, return the difference.
    //  4. If no such difference is found, return 0.
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 2; i >= 0; i--)
        {
            int x = nums2[0] - nums1[i];
            int k = 0;
            for (int j = i; j < n1 && k < n2; j++)
                if (nums1[j] + x == nums2[k])
                    k++;
            if (k == n2)
                return x;
        }
        return 0;
    }
};
