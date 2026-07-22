// Link: https://leetcode.com/problems/total-hamming-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * 32) where n is the number of elements in the input array and 32 is the number of bits in an integer
    // SC: O(1) as we are using a constant amount of space
    // Approach:
    //  1. For each bit position from 0 to 31, count the number of integers in the input array that have a 1 at that bit position (ones) and the number of integers that have a 0 at that bit position (zeros).
    //  2. The contribution of that bit position to the total Hamming distance is given by the product of ones and zeros, as each pair of integers with different bits at that position contributes 1 to the Hamming distance.
    //  3. Sum the contributions from all bit positions to get the total Hamming distance.
    //  4. Return the total Hamming distance as an integer.
    int totalHammingDistance(vector<int> &nums)
    {
        long long total = 0;
        int n = nums.size();

        for (int bit = 0; bit < 32; ++bit)
        {
            int ones = 0;

            for (int num : nums)
            {
                ones += (static_cast<unsigned int>(num) >> bit) & 1U;
            }

            int zeros = n - ones;
            total += static_cast<long long>(ones) * zeros;
        }

        return static_cast<int>(total);
    }
};
