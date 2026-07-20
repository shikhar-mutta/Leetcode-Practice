// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(1)
    //  Approach:
    //  1. We can use two pointers to solve this problem. We can initialize two pointers, one at the beginning of the array and one at the end of the array.
    //   2. We can then calculate the sum of the two numbers at the two pointers. If the sum is equal to the target, we can return the indices of the two numbers. If the sum is less than the target, we can move the left pointer to the right. If the sum is greater than the target, we can move the right pointer to the left.
    //  3. We can continue this process until we find the two numbers that add up to the target or until the two pointers meet.
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            if (sum < target)
                l++;
            else
                r--;
        }
        return {};
    }
};
