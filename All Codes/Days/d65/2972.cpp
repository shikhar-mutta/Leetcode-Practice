// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: let p = length of the strictly increasing prefix, s = length of the strictly
// increasing suffix. If the whole array is increasing, every subarray removal works. Otherwise,
// for each kept-prefix length l (0..p), find (two-pointer, monotonic since the prefix values are
// increasing) the smallest suffix-start index j >= max(l, n-s) with nums[j] > nums[l-1] (or no
// constraint if l==0); every j' >= j also works since the suffix is increasing, contributing
// (n-j+1) valid removal choices.
class Solution
{
public:
    long long incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int p = 1;
        while (p < n && nums[p] > nums[p - 1])
            p++;
        if (p == n)
            return (long long)n * (n + 1) / 2;

        int s = 1;
        while (s < n && nums[n - 1 - s] < nums[n - s])
            s++;

        long long ans = 0;
        int j = max(0, n - s);
        for (int l = 0; l <= p; l++)
        {
            if (j < l)
                j = l;
            while (j < n && l > 0 && nums[j] <= nums[l - 1])
                j++;
            ans += (n - j + 1);
        }
        return ans;
    }
};
