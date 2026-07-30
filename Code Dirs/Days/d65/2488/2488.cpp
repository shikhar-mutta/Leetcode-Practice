// Link: https://leetcode.com/problems/count-subarrays-with-median-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: Let p be the index of k in nums. For each i >= p, maintain a balance bal = #nums[i] > k - #nums[i] < k. Count the number of occurrences of each balance in cnt[]. For each i <= p, maintain a balance bal = #nums[i] > k - #nums[i] < k. The number of valid subarrays with median k is cnt[-bal] + cnt[-bal + 1].
class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> cnt(2 * n + 1, 0);
        int p = find(nums.begin(), nums.end(), k) - nums.begin(), res = 0;

        for (int i = p, bal = 0; i < n; i++)
        {
            bal += nums[i] == k ? 0 : nums[i] < k ? -1
                                                  : 1;
            cnt[bal + n]++;
        }

        for (int i = p, bal = 0; i >= 0; i--)
        {
            bal += nums[i] == k ? 0 : nums[i] < k ? -1
                                                  : 1;
            res += cnt[-bal + n] + cnt[-bal + 1 + n];
        }

        return res;
    }
};