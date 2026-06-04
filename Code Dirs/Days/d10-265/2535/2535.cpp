// Link: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * log(maxNum)), SC: O(1)
    int differenceOfSum(vector<int> &nums)
    {
        int elementSum = 0, digitSum = 0;
        for (int num : nums)
        {
            elementSum += num;
            while (num > 0)
            {
                digitSum += num % 10;
                num /= 10;
            }
        }
        return abs(elementSum - digitSum);
    }
};
