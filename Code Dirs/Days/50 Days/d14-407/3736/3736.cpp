// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minMoves(vector<int> &nums)
    {
        int maxElem = *max_element(nums.begin(), nums.end());
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        return n * maxElem - sum;
    }
};
