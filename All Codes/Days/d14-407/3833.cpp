// Link: https://leetcode.com/problems/count-dominant-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int dominantIndices(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum = sum - nums[i];
            if (nums[i] > (sum / (n - 1 - i)))
                count++;
        }
        return count;
    }
};
