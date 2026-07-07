// Link: https://leetcode.com/problems/wiggle-sort-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) SC: O(n)
    // Sort the array and fill the odd slots with the largest half, then even slots with the rest,
    // both in descending order so duplicates end up far apart.
    void wiggleSort(vector<int> &nums)
    {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), j = n - 1;
        // Fill odd slots with the largest half, then even slots with the rest,
        // both in descending order so duplicates end up far apart.
        for (int i = 1; i < n; i += 2)
            nums[i] = sorted[j--];
        for (int i = 0; i < n; i += 2)
            nums[i] = sorted[j--];
    }
};
