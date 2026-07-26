// Link: https://leetcode.com/problems/separate-black-and-white-balls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – single left-to-right pass over the string
// SC: O(1) – only two counters
// Approach: Greedy. To push all '1's to the right, scan left to right.
// Track count of '1's seen so far (ones). When a '0' is encountered,
// it must swap past every '1' to its left → add ones to swaps.
// This gives the minimum adjacent swaps to separate 0s and 1s.
class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ones = 0;
        long long swaps = 0;
        for (char ch : s)
        {
            if (ch == '1')
            {
                ones++;
            }
            else
            {
                swaps += ones;
            }
        }
        return swaps;
    }
};