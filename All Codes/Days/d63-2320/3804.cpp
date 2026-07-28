// Link: https://leetcode.com/problems/number-of-centered-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
//  Approach: for each start index, extend the subarray right while
//  tracking the running sum and a set of contained values; count it if
//  the sum equals some element already seen in the subarray.
class Solution
{
public:
    bool v[200001] = {0};
    int centeredSubarrays(vector<int> &nums)
    {
        int ans = 0, OFFSET = 100000;
        for (int i = 0, sum = 0; i < nums.size(); ++i, sum = 0)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                v[nums[j] + OFFSET] = 1;
                if (sum + OFFSET >= 0 && sum + OFFSET <= 2 * OFFSET &&
                    v[sum + OFFSET])
                    ++ans;
            }
            for (int j = i; j < nums.size(); ++j)
                v[nums[j] + OFFSET] = 0;
        }
        return ans;
    }
};