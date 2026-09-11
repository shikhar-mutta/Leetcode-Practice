// Link: https://leetcode.com/problems/divide-array-into-equal-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using a bitset. TC: O(n), SC: O(1).
    bool divideArray(vector<int> &nums)
    {
        bitset<501> seen; // Assuming numbers are in the range [0, 500].
        for (int num : nums)
            seen.flip(num); // Flip the bit corresponding to the number.
        return seen.none(); // If all bits are 0.
    }
};
