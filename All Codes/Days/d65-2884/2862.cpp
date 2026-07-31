// Link: https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*sqrt(N)), SC: O(1)
// Approach: For each index i, we can add the value of nums[i] to the sum. Then, we can add the values of nums[i * j^2] for all j >= 2, as long as i * j^2 <= n. We can keep track of the maximum sum we have seen so far and return it at the end.
class Solution
{
public:
    long long maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            long long value = nums[i - 1];
            if (value < 0)
            {
                continue;
            }
            for (int j = 2; true; ++j)
            {
                int index = i * j * j;
                if (index > n)
                    break;
                value += nums[index - 1];
                nums[index - 1] = -1;
            }
            ans = max(ans, value);
        }
        return ans;
    }
};
