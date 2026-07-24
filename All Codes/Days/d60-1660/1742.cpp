// Link: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//    Approach:
//      1. We can use a prefix sum array to calculate the total number of candies of each type.
//      2. For each query, we can check if it is possible to eat the favorite candy on the favorite day by checking if the total number of candies of the favorite type is greater than or equal to the number of days multiplied by the maximum number of candies that can be eaten per day.
//      3. We can also check if the total number of candies of the favorite type is less than or equal to the number of days multiplied by the minimum number of candies that can be eaten per day.
//   Note: We need to check both conditions to ensure that it is possible to eat the favorite candy on the favorite day.
class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {

        std::array<int, 50> countArray{};
        for (uint32_t i = lowLimit; i <= highLimit; ++i)
        {
            uint32_t testVal = i;
            uint32_t sum = 0;
            while (testVal != 0)
            {
                sum += testVal % 10;

                testVal /= 10;
            }

            ++countArray[sum];
        }

        int maxBucket = *std::max_element(countArray.begin(), countArray.end());

        return maxBucket;
    }
};