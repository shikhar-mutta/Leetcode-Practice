// Link: https://leetcode.com/problems/maximum-subarray-min-product/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach:
//    1. We can use a monotonic stack to find the next smaller element to the left and right of each element in the array.
//    2. We can use a prefix sum array to calculate the sum of the subarray for each element.
//    3. We can iterate through the array and for each element, we can calculate the min-product of the subarray using the next smaller elements and the prefix sum array.
//    4. We can keep track of the maximum min-product and return it modulo 10^9 + 7.
//    5. We can use long long to avoid integer overflow when calculating the min-product.
class Solution
{
public:
    const int mod = 1e9 + 7;

    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> stk;
        stk.reserve(n);

        vector<long long> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }

        long long sum = 0;

        for (int i = 0; i <= n; i++)
        {
            int num = (i < n) ? nums[i] : 0;
            while (!stk.empty() && nums[stk.back()] > num)
            {
                int cur = stk.back();
                stk.pop_back();
                long long subarray;

                if (stk.empty())
                    subarray = pref[i - 1];
                else
                    subarray = pref[i - 1] - pref[stk.back()];

                sum = max(sum, (subarray * nums[cur]));
            }
            stk.push_back(i);
        }

        return sum % mod;
    }
};