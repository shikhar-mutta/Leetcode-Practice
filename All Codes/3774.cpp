// Link: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(1)
    int absDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return abs(accumulate(nums.begin(), nums.begin() + k, 0) - accumulate(nums.end() - k, nums.end(), 0));
    }
};
