// Link: https://leetcode.com/problems/apply-operations-to-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: use ans vector. TC: O(n), SC: O(n)
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0); // Initialize the answer vector with zeros
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                ans[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
            else
                ans[i] = nums[i];
        }
        ans[n - 1] = nums[n - 1];
        // Shift all zeros to the end
        int writeIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != 0) // Write non-zero elements to the answer vector
            {
                ans[writeIndex++] = ans[i];
            }
        }
        while (writeIndex < n) // Fill the remaining positions with zeros
        {
            ans[writeIndex++] = 0;
        }
        return ans;
    }
};
