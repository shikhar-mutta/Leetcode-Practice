// Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size(), sum = nums[0];
        // Calculate the sum of the longest prefix of consecutive integers starting from 1
        for (int i = 1; i < n && nums[i] == nums[i - 1] + 1; i++)
            sum += nums[i];

        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(sum))
            sum++;
        return sum;
    }
};
