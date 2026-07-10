// Link: https://leetcode.com/problems/smallest-range-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn)
    // SC: O(1)
    // Approach: Sort the array and then iterate through the array to find the minimum range by considering the maximum and minimum values after adding/subtracting k.
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0]; // all shifted the same way
        for (int i = 0; i + 1 < n; i++)
        {
            // nums[0..i] go up by k, nums[i+1..n-1] go down by k
            int high = max(nums[i] + k, nums[n - 1] - k);
            int low = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, high - low);
        }
        return ans;
    }
};
