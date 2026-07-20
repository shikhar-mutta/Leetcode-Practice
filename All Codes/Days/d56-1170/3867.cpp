// Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(nlog(max))
    // SC: O(1)
    //  Approach:
    //  1. Find the maximum element in the array and replace each element with the GCD of itself and the maximum element.
    //  2. Sort the modified array in ascending order.
    //  3. Initialize two pointers, one at the beginning of the array and the other at the end of the array. While the left pointer is less than the right pointer, calculate the GCD of the elements at the left and right pointers, add it to the sum, and move the left pointer to the right and the right pointer to the left.
    //  4. Return the sum of the GCDs of the formed pairs.
    long long gcdSum(vector<int> &nums)
    {
        int max = 0, n = nums.size();
        for (int &num : nums)
        {
            max = (num > max) ? num : max;
            num = gcd(num, max);
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int l = 0, r = n - 1; l < r; l++, r--)
            sum += gcd(nums[l], nums[r]);
        return sum;
    }
};
