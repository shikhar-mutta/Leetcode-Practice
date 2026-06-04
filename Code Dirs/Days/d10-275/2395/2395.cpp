// Link: https://leetcode.com/problems/find-subarrays-with-equal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: Use hash set to store sums. TC: O(n), SC: O(n)
    bool findSubarrays(vector<int> &nums)
    {
        unordered_set<int> sums;
        for (int i = 1; i < nums.size(); i++)
        {
            int sum = nums[i] + nums[i - 1];
            if (sums.count(sum)) // if the sum is already in the set, we found a duplicate
                return true;
            sums.insert(sum); // otherwise, add the sum to the set
        }
        return false;
    }
};
