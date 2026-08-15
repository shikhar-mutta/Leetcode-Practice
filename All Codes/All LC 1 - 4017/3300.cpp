// Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * log(max(nums[i]))), SC: O(1)
    int minElement(vector<int> &nums)
    {
        int minVal = INT_MAX, sumDigits;
        for (int num : nums)
        {
            sumDigits = 0;
            while (num > 0)
            {
                sumDigits += num % 10;
                num /= 10;
            }
            minVal = min(minVal, sumDigits);
        }
        return minVal;
    }
};
