// Link: https://leetcode.com/problems/even-number-of-knight-moves/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: Check if the parity of the sum of coordinates is the same for both points.
class Solution
{
public:
    bool canReach(vector<int> &start, vector<int> &target)
    {
        return ((start[0] + start[1]) % 2) == ((target[0] + target[1]) % 2);
    }
};