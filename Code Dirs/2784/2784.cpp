// Link: https://leetcode.com/problems/check-if-array-is-good/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn), SC: O(1)
    bool isGood(vector<int> &nums)
    {
        int n = nums.size();
        // Sort needed, bcz check every numbers from 1 to n-1, if not found return false
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
            if (nums[i] != i + 1)
                return false;
        return nums[n - 1] == n - 1; // last element must also be n-1
    }
};
