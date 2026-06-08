// Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * log(m)) . SC: O(1)
    int smallestIndex(vector<int> &nums)
    {

        auto digitSum = [](int num)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (digitSum(nums[i]) == i)
                return i;
        }
        return -1;
    }
};
