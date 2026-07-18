// Link: https://leetcode.com/problems/largest-divisible-subset/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n)
    // Approach: We can use dynamic programming to solve this problem. We can sort the input
    // array and then use a dp array to keep track of the length of the largest divisible subset
    // that ends with each element. We can also use a hash array to keep track of the previous
    // index of each element in the largest divisible subset. Finally, we can reconstruct the
    // largest divisible subset by following the hash array from the last index of the largest
    // subset.
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastindex = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0)
                {
                    if (1 + dp[prev] > dp[i])
                    {
                        dp[i] = dp[prev] + 1;
                        hash[i] = prev;
                    }
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> res;
        res.push_back(nums[lastindex]);
        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            res.push_back(nums[lastindex]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};