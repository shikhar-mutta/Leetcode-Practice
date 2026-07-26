// Link: https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the doubled array
// Approach: split target into full = target/sum whole traversals of nums
// (each costing n elements) plus a remainder rem = target%sum that must be
// covered by some (possibly wrapping) contiguous subarray. Search for the
// shortest such subarray via sliding window over nums doubled (covers every
// possible wraparound start), since all values are positive. Answer is
// full*n + that window length, or -1 if rem>0 has no matching window.
class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        long long sum = 0;
        int n = nums.size();

        for (int x : nums)
            sum += x;

        long long full = target / sum;
        long long rem = target % sum;

        if (rem == 0)
            return full * n;

        vector<int> arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());

        long long curr = 0;
        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < 2 * n; right++)
        {
            curr += arr[right];

            while (curr > rem && left <= right)
                curr -= arr[left++];

            if (curr == rem)
                ans = min(ans, right - left + 1);
        }

        if (ans == INT_MAX)
            return -1;

        return full * n + ans;
    }
};
