// Link: https://leetcode.com/problems/smallest-range-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        // The smallest range will be the difference between the maximum and minimum elements in the array after adding or subtracting k from each element.
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        return max(0, mx - mn - 2 * k);
    }
};
