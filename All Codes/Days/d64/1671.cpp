// Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the size of the input array
// SC: O(n) where n is the size of the input array
// Approach: We can use the concept of Longest Increasing Subsequence (LIS) and Longest Decreasing Subsequence (LDS) to solve this problem. We can find the LIS from the left and the LDS from the right for each element in the array. The minimum number of removals required to make the array a mountain array will be equal to the size of the array minus the maximum length of the mountain array that can be formed using the LIS and LDS.
class Solution
{
public:
    vector<int> func(vector<int> &nums)
    {
        vector<int> lis;
        vector<int> lisLen(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (lis.empty() || nums[i] > lis.back())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int idx =
                    lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
            lisLen[i] = lis.size();
        }
        return lisLen;
    }
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis = func(nums);
        reverse(nums.begin(), nums.end());
        vector<int> lds = func(nums);
        reverse(lds.begin(), lds.end());
        int ans = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (lis[i] > 1 && lds[i] > 1)
            {
                ans = min(ans, n - (lis[i] + lds[i] - 1));
            }
        }
        return ans;
    }
};