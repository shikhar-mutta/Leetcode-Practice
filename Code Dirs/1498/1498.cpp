// Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        int MOD = 1e9 + 7;

        // count sort instead of normal sort .. rest is same

        int freq[1000001] = {0}; // as max element can be 10^6
        int largest = 0;

        for (int x : nums) // cnt freq & find largest element
        {
            freq[x]++;
            largest = max(largest, x);
        }

        int idx = 0; // fill the nums array with sorted elements using freq array
        for (int x = 1; x <= largest; x++)
        {
            int f = freq[x];

            if (f == 0)
                continue;
            // fill the array with x for f times
            fill(nums.begin() + idx, nums.begin() + idx + f, x);
            // move the idx forward by f
            idx += f;
        }

        int ans = 0;
        // precompute powers of 2 up to n
        vector<int> pow2(n + 1, 0);
        pow2[0] = 1;

        for (int i = 1; i <= n; i++) // make the pow2 array where pow2[i] = 2^i % MOD
            pow2[i] = (pow2[i - 1] << 1) % MOD;

        // two pointer approach
        int st = 0;
        int end = n - 1;

        while (st <= end)
        {
            if (nums[st] + nums[end] <= target)
            { // power of 2 for the number of elements between st and end
                int subSeq = pow2[end - st];
                ans = (ans + subSeq) % MOD; // add to ans
                st++;
            }
            else
            {
                end--;
            }
        }
        return ans;
    }
};