// Link: https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 1, sum = 0;
            for (int num : nums)
            {
                if (sum + num > mid)
                    count++, sum = num;
                else
                    sum += num;
                if (count > k)
                    break;
            }
            if (count > k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
