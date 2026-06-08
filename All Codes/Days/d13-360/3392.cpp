// Link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countSubarrays(vector<int> &nums)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
                count++;
        }
        return count;
    }
};
