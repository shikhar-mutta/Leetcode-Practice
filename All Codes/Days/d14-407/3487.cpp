// Link: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int maxSum(vector<int> &nums)
    {
        int n = nums.size(), maxSum = 0, minMine = INT_MIN, cnt = 0;
        unordered_set<int> seen; // To track unique elements in the current window
        for (int i = 0; i < n; i++)
        {
            seen.insert(nums[i]);
        }
        for (auto num : seen)
        {
            if (num >= 0)
            {
                maxSum += num;
                cnt++;
            }
            else
            {
                minMine = max(minMine, num);
            }
        }
        return cnt ? maxSum : minMine;
    }
};
