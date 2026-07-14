// Link: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + m), SC: O(n)
// Approach:
//  1. Count the frequency of each index in the requests using a prefix sum array.
//  2. Sort the frequency array and the nums array in non-decreasing order.
//  3. Multiply the corresponding elements of the two sorted arrays and take the sum modulo 1e9 + 7.

class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = nums.size();
        int m = requests.size();
        vector<int> freq(n, 0);
        for (auto &r : requests)
        {
            freq[r[0]]++;

            if (r[1] + 1 < n)
                freq[r[1] + 1]--;
        }
        for (int i = 1; i < n; i++)
            freq[i] += freq[i - 1];
        sort(begin(freq), end(freq));
        sort(begin(nums), end(nums));
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + 1LL * freq[i] * nums[i]) % mod;
        }
        return ans;
    }
};