// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int count(vector<int> &nums, int k)
    {
        vector<int> mp(nums.size() + 1, 0);
        int count1 = 0;
        int count = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (mp[nums[r]] == 0)
            {
                count1++;
            }
            mp[nums[r]]++;
            while (count1 > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    count1--;
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return count(nums, k) - count(nums, k - 1);
    }
};