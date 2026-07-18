// Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countPartitions(vector<int> &nums)
    {
        int cnt = 0, n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), left = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum -= nums[i];
            left += nums[i];

            if (abs(left - sum) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
