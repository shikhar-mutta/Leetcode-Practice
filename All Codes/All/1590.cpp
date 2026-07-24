// Link: https://leetcode.com/problems/make-sum-divisible-by-p/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach:
    //   1. We will first calculate the total sum of the array and find the remainder when divided by p. This will be our target.
    //   2. We will then use a hashmap to store the last index of each prefix sum modulo p.
    //  3. We will iterate through the array and for each element, we will calculate the current prefix sum modulo p and check if we have seen the required prefix sum that would make the subarray sum divisible by p. If we have seen it, we will update the result with the length of the subarray.
    //  4. Finally, we will return the length of the smallest subarray that can be removed to make the sum of the remaining elements divisible by p. If no such subarray exists, we will return -1.
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        long long total = 0;
        for (int x : nums)
            total += x;
        int target = total % p;
        if (target == 0)
            return 0;

        unordered_map<int, int> last{{0, -1}};
        int res = n, cur = 0;
        for (int j = 0; j < n; ++j)
        {
            cur = (cur + nums[j]) % p;
            int want = ((cur - target) % p + p) % p;
            auto it = last.find(want);
            if (it != last.end())
                res = min(res, j - it->second);
            last[cur] = j;
        }
        return res < n ? res : -1;
    }
};