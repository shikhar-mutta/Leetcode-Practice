// Link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of special floors.
    // SC: O(1) where n is the number of special floors.
    // Approach:
    //   1. We will sort the special floors in ascending order.
    //   2. We will iterate through the special floors and calculate the maximum number of consecutive floors without special floors by taking the difference between the current special floor and the previous special floor and subtracting 1 from the difference.
    //   3. We will also check the number of consecutive floors without special floors between the bottom floor and the first special floor and between the last special floor and the top floor.
    //   4. We will return the maximum number of consecutive floors without special floors.
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());
        int best = special[0] - bottom;
        for (int i = 1; i < (int)special.size(); i++)
            best = max(best, special[i] - special[i - 1] - 1);
        best = max(best, top - special.back());
        return best;
    }
};
