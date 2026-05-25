// Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, ans = 1;
        long long windowSum = 0;

        for (int r = 0; r < (int)nums.size(); r++)
        {
            windowSum += nums[r];
            // cost to raise all elements in [l,r] to nums[r]
            while ((long long)nums[r] * (r - l + 1) - windowSum > k)
            {
                windowSum -= nums[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};