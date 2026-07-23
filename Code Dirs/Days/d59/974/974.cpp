// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> count(k, 0);
        count[0] = 1;
        int prefix_sum = 0;
        int ans = 0;
        for (int num : nums)
        {
            prefix_sum += num;
            int rem = (prefix_sum % k + k) % k;
            ans += count[rem];
            count[rem]++;
        }

        return ans;
    }
};