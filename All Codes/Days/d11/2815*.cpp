// Link: https://leetcode.com/problems/max-pair-sum-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * log(m)) where m is max number in the array, SC: O(1)
    int maxSum(vector<int> &nums)
    {
        int ans = -1;
        int n = nums.size();
        // Track the maximum value for each digit from 0 to 9
        vector<int> m_val(10, 0);

        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            int m_d = 0;
            // Find m_d, the maximum digit in the current number
            while (curr > 0)
            {
                int rem = curr % 10;
                m_d = max(m_d, rem);
                curr /= 10;
            }
            // Update ans if there is a previously seen number with the same maximum digit
            if (m_val[m_d] > 0)
            {
                ans = max(ans, nums[i] + m_val[m_d]);
            }
            // Update the maximum value for the current maximum digit
            m_val[m_d] = max(m_val[m_d], nums[i]);
        }
        return ans;
    }
};