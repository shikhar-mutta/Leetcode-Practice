// Link: https://leetcode.com/problems/single-number-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of elements in the input array nums. We iterate through the array once, performing constant-time operations for each element.
    // SC: O(1) as we are using a constant amount of extra space for the variables ones and twos, regardless of the input size.
    // Approach:
    // 1. We maintain two variables, ones and twos, to keep track of the bits that have appeared once and twice, respectively.
    // 2. For each number in the array, we update ones and twos using bitwise operations:
    //    - ones is updated to include the current number if it has appeared an odd number of times (i.e., once or three times).
    //    - twos is updated to include the current number if it has appeared an even number of times (i.e., twice).
    // 3. The bitwise AND with the negation of the other variable ensures that bits that have appeared three times are cleared from both ones and twos.
    // 4. After processing all numbers, ones will contain the bits of the number that appears exactly once, which is returned as the result.
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;
        for (int x : nums)
        {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};
