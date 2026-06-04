// Link: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maximizeSum(vector<int> &nums, int k)
    {
        int maxNum = *max_element(nums.begin(), nums.end());
        return k * maxNum + (k * (k - 1)) / 2;
    }
};
