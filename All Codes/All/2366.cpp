// Link: https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach: We can iterate through the array from right to left and keep track of the maximum allowed value for the current element. If the current element is greater than the maximum allowed value, we can calculate the number of replacements needed to make it less than or equal to the maximum allowed value.
class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        int maxAllowed = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= maxAllowed)
            {
                maxAllowed = nums[i];
                continue;
            }
            long long k = (nums[i] + maxAllowed - 1) / maxAllowed;
            ans += k - 1;
            maxAllowed = nums[i] / k;
        }
        return ans;
    }
};
