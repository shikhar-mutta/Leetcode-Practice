// Link: https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * log(max(nums[i]))), where n is the size of the input array nums.
// SC: O(1), as we are using a constant amount of extra space for variables
// Approach:
//  1. We iterate through each element of the input array nums using a nested loop.
//  2. For each element, we check if it is divisible by k. If not, we skip to the next element.
//  3. If it is divisible by k, we initialize a variable gd to the current element and start another loop to iterate through the remaining elements of the array
//  4. In the inner loop, we calculate the GCD of gd and the current element using the built-in gcd function. If the GCD is equal to k, we increment the count of valid subarrays. If the GCD becomes less than k or is not divisible by k, we break out of the inner loop as it is not possible to find a valid subarray starting from the current element.
//  5. Finally, we return the count of valid subarrays.
class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % k != 0)
                continue;
            int gd = nums[i];
            for (int j = i; j < n; j++)
            {
                gd = gcd(gd, nums[j]);

                if (gd == k)
                    count++;
                else if (gd < k || gd % k != 0)
                    break;
            }
        }

        return count;
    }
};