// Link: https://leetcode.com/problems/increasing-triplet-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) .
    //  SC: O(1) .
    // Approach:
    //  1. We can iterate through the input vector nums and keep track of the smallest and second smallest elements seen so far. If we encounter an element that is greater than both the smallest and second smallest elements, we have found an increasing triplet subsequence and return true. If we finish iterating through the vector without finding an increasing triplet subsequence, we return false.
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums)
        {
            if (x <= first)
                first = x;
            else if (x <= second)
                second = x;
            else
                return true;
        }
        return false;
    }
};
