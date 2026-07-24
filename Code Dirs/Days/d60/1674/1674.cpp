// Link: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + limit) where n is the length of the input array and limit is the maximum value of the elements in the array.
    // SC: O(limit) for storing the difference array.
    // Approach:
    //       1. Use a difference array to keep track of the changes in the number of moves required for each possible sum of pairs.
    //       2. For each pair of elements (a, b) in the array, update the difference array to reflect the number of moves required to make the sum of the pair equal to each possible sum in the range [2, 2*limit].
    //       3. Iterate through the difference array to find the minimum number of moves required to make the array complementary.
    int minMoves(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0); // diff[s] = change at sum = s

        for (int i = 0; i < n / 2; i++)
        {
            int a = nums[i], b = nums[n - i - 1];
            int lo = min(a, b), hi = max(a, b);

            // base cost 2 for every sum in [2, 2*limit]
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // cost 1 (instead of 2) for sum in [lo+1, hi+limit]
            diff[lo + 1] -= 1;
            diff[hi + limit + 1] += 1;

            // cost 0 (instead of 1) exactly at sum = a+b
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX, cur = 0;
        for (int sum = 2; sum <= 2 * limit; sum++)
        {
            cur += diff[sum];
            ans = min(ans, cur);
        }
        return ans;
    }
};
