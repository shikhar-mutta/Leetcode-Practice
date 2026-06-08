// Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minOperations(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
};
