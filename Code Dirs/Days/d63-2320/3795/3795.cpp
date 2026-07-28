// Link: https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: similar to the standard sliding window, but with a fixed-size array
//  to track frequencies instead of a hash map.
class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {
        int left = 0, result = INT_MAX, n = nums.size();
        long long sum = 0;
        int cnt[100005] = {0};

        for (int right = 0; right < n; right++)
        {
            // move into the sliding window
            int x = nums[right];
            cnt[x]++;
            if (cnt[x] == 1)
                sum += x;

            while (sum >= k)
            {
                result = min(result, right - left + 1);

                // move out the sliding window
                int out = nums[left];
                cnt[out]--;
                if (cnt[out] == 0)
                {
                    sum -= out;
                }
                left++;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};