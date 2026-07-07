// Link: https://leetcode.com/problems/valid-triangle-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
// Approach: Sort the array and fix the largest side nums[k]. Then use two pointers to count pairs with sum > nums[k].
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        // Fix the largest side nums[k]; two pointers count pairs with sum > nums[k].
        for (int k = n - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    count += j - i; // every index in (i, j] works with this j
                    j--;
                }
                else
                    i++;
            }
        }
        return count;
    }
};
