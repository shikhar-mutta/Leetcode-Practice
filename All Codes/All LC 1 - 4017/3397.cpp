// Link: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// TC: O(nlogn) + O(n) = O(nlogn)
// SC: O(1)
//  Approach:
//  1. Sort the array of numbers.
//  2. Subtract k from the first element to maximize the number of distinct elements.
//  3. Iterate through the sorted array and for each element, calculate the difference between it and the previous element. If the difference is less than or equal to k, subtract the difference from the current element to make it distinct. If the difference is greater than k, subtract k from the current element to make it distinct. If the difference is negative, add k to the current element to make it distinct.
//  4. Count the number of distinct elements in the modified array and return the count.
//  5. The final answer is the count of distinct elements in the modified array.
class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        nums[0] -= k;
        for (int i = 1; i < nums.size(); i++)
        {
            int target = nums[i] - nums[i - 1] - 1;
            if (target <= k && target >= -k)
                nums[i] -= target; // else go for max Reach
            else if (target > k)
                nums[i] -= k;
            else
                nums[i] += k;
        }
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i - 1] != nums[i])
                ans++;
        return ans;
    }
};