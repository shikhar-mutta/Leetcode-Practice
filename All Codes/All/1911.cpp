// Link: https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//    1. We can use dynamic programming to keep track of the maximum alternating sum at even and odd positions.
//    2. We can iterate through the array and for each element, we can update the maximum alternating sum at even and odd positions based on the previous values.
//    3. Finally, we can return the maximum alternating sum at even positions as the result.
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long even = 0, odd = 0;
        for (int x : nums)
        {
            long long newEven = max(even, odd + x); // add x at an even position
            long long newOdd =
                max(odd, even - x); // subtract x at an odd position
            even = newEven;
            odd = newOdd;
        }
        return even;
    }
};
