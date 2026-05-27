// Link: https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // Approach 2: Dynamic Programming with Space Optimization
        int res = nums[0], maxProd = nums[0], minProd = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // If the current number is negative, we swap the maximum and minimum products because multiplying by a negative number will flip their signs.
            if (nums[i] < 0)
                swap(maxProd, minProd);

            // Update the maximum and minimum products for the current position.
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            res = max(res, maxProd);
        }
        return res;

        // // Approach 1: Dynamic Programming (Easy to Understand)
        // int n = nums.size();
        // int pre = 1, suf = 1, ans = INT_MIN;
        // for (int i = 0; i < n; i++){
        //     pre *= nums[i];
        //     suf *= nums[n - 1 - i];
        //     ans = max(ans, max(pre, suf));
        //     if (pre == 0)
        //         pre = 1;
        //     if (suf == 0)
        //         suf = 1;
        // }
        // return ans;
    }
};