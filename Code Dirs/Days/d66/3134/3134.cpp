// Link: https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Use binary search to find the median of the uniqueness array. The uniqueness array is defined as the number of distinct elements in each subarray of the input array. We can use a sliding window approach to count the number of distinct elements in each subarray. We can use a frequency array to keep track of the count of each element in the current window. We can then use binary search to find the median of the uniqueness array by checking if the number of subarrays with at most k distinct elements is less than or equal to half of the total number of subarrays.
int freq[100001] = {};
class Solution
{
    long long check(vector<int> &nums, int k)
    {
        const int n = nums.size();
        long long res = 0;
        int i = 0;
        for (int j = 0, d = 0; j < n; ++j)
        {
            if (freq[nums[j]]++ == 0)
            {
                ++d;
            }
            while (d > k)
            {
                if (--freq[nums[i]] == 0)
                {
                    --d;
                }
                ++i;
            }
            res += j - i + 1;
        }
        while (i < n)
        {
            --freq[nums[i]];
            ++i;
        }
        return res;
    }

public:
    int medianOfUniquenessArray(vector<int> &nums)
    {
        const int n = nums.size();
        long long subs = 1ll * n * (n + 1) / 2;
        long long median = (subs - 1) / 2 + 1;
        int l = 1, r = n;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (check(nums, m) < median)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
