// Link: https://leetcode.com/problems/append-k-integers-with-minimal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of elements in nums.
    // SC: O(n) where n is the number of elements in nums.
    // Approach:
    //  1. We will sort the nums array and remove duplicates.
    //  2. We will iterate through the nums array and for each number, we will calculate the number of integers that can be added to the sum without exceeding k.
    //  3. We will keep track of the remaining integers that can be added to the sum and the previous number.
    //  4. We will return the sum of the integers that can be added to the sum.
    //  5. If there are still remaining integers that can be added to the sum, we will add them to the sum.
    long long minimalKSum(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        long long sum = 0;
        long long remaining = k;
        long long prev = 0;
        for (int num : nums)
        {
            long long gapCount = num - 1 - prev;
            if (gapCount > 0)
            {
                long long take = min(gapCount, remaining);
                sum += take * (prev + 1 + prev + take) / 2;
                remaining -= take;
                if (remaining == 0)
                    return sum;
            }
            prev = num;
        }
        sum += remaining * (prev + 1 + prev + remaining) / 2;
        return sum;
    }
};
