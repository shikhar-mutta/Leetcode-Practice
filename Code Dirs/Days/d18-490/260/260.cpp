// Link: https://leetcode.com/problems/single-number-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long xor_sum = 0;

        for (int n : nums) // get xor of all numbers(get xor of 2 unique numbers)
            xor_sum ^= n;

        // Get lower Bit of xor_sum, which is different between 2 unique numbers
        long long lowest_set_bit = xor_sum & ~(xor_sum - 1);

        int x = 0, y = 0;

        for (int n : nums)
        {
            if (n & lowest_set_bit) // bit set
                x ^= n;
            else // bit not set
                y ^= n;
        }

        return {x, y};
    }
};