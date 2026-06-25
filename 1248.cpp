// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // exactly(k) odds = atMost(k) - atMost(k-1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        int left = 0, odds = 0, res = 0;
        for (int right = 0; right < (int)nums.size(); right++)
        {
            odds += nums[right] & 1;
            while (odds > k)
                odds -= nums[left++] & 1;
            res += right - left + 1; // subarrays ending at right with <=k odds
        }
        return res;
    }
};
