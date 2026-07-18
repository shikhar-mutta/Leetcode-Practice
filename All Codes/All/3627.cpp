// Link: https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TC: O(nlogn)
    //SC: O(1)
    // Approach:
    // 1. We can find the maximum median sum of subsequences of size 3 by first sorting the array in non-decreasing order.
    // 2. We can then iterate through the array and for every third element starting from the middle of the array, we can add it to the answer.
    // 3. Finally, we can return the answer as the maximum median sum of subsequences of size 3.
    long long maximumMedianSum(vector<int> &nums)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = (n / 3); i < n; i = i + 2)
        {
            ans += nums[i];
        }
        return ans;
    }
};