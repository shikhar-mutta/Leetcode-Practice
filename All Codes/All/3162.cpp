// Link: https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogm + nm) SC: O(1)
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size(), count = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (nums1[i] < k * nums2[j]) // Early Stopping
                    break;
                else if (nums1[i] % (k * nums2[j]) == 0)
                    count++;

        return count;
    }
};
