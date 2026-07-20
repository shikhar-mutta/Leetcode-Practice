// Link: https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(1)
    //  Approach:
    //  1. We will iterate through the array and for each element, we will find the sum of the subarray starting from that element.
    //  2. We will check if the sum of the subarray is valid by checking if the first and last digit of the sum is equal to x.
    //  3. If the sum is valid, we will increment the count.
    int countValidSubarrays(vector<int> &nums, int x)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum % 10 != x)
                    continue;
                long long t = sum;
                while (t >= 10)
                    t /= 10;
                if (t == x)
                    count++;
            }
        }
        return count;
    }
};
