// Link: https://leetcode.com/problems/contiguous-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach:
//  1. Use a balance variable to keep track of the difference between the number of 1s and 0s in the array.
//  2. Use a vector to store the first index of each balance value.
//  3. Iterate through the array and update the balance variable. If the balance value has been seen before, calculate the length of the subarray and update the maximum length. If the balance value has not been seen before, store the current index as the first index of that balance value.
//  4. Return the maximum length of the subarray with equal number of 0s and 1s.
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        // the first index of each balance
        // range: [-n, n]
        vector<int> firstIndex(2 * n + 1, -2);
        int balance = 0;
        int max_len = 0;
        // virtual prefix: balance = 0
        firstIndex[n] = -1;
        for (int i = 0; i < n; ++i)
        {
            balance += nums[i] == 1 ? 1 : -1;
            // index in the balance array
            int index = balance + n;
            if (firstIndex[index] != -2)
                max_len = max(max_len, i - firstIndex[index]);
            else
                firstIndex[index] = i;
        }
        return max_len;
    }
};