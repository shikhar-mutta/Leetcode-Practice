// Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// TC: O(n) where n is the length of the input array.
// SC: O(1) for storing the result.
// Approach:
//       1. Calculate the total sum of the array and store it in sum_right.
//       2. Iterate through the array and for each element, calculate the sum of absolute differences using the formula:
//           ans[i] = (sum_right - (n - i - 1) * num) + (i * num - sum_left)
//       3. Update sum_right and sum_left accordingly for the next iteration.
//       4. Return the result array ans.
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        int sum_right = accumulate(nums.begin(), nums.end(), 0);

        vector<int> ans(n);

        int sum_left = 0;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            sum_right -= num;

            ans[i] = (sum_right - (n - i - 1) * num) + (i * num - sum_left);

            sum_left += num;
        }

        return ans;
    }
};