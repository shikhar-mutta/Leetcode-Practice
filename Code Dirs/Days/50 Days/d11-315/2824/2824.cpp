// Link: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n) due to sorting, SC: O(1)
    int countPairs(vector<int> &nums, int target)
    {
        int count = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;

        while (left < right)
            if (nums[left] + nums[right] < target)
            {
                count += right - left; // All pairs (left, left+1), (left, left+2), ..., (left, right)
                left++;
            }
            else
                right--;

        return count;
    }
};
