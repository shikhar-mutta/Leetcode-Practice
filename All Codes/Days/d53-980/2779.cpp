// Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the size of nums and m is the maximum value in nums
    // SC: O(m) where m is the maximum value in nums
    // Approach:
    //  1. Create a vector v of size x + 2 where x is the    maximum value in nums + k.
    //  2. For each element in nums, increment the value at index max(0, nums[i] - k) and decrement the value at index nums[i] + k + 1 in v.
    //  3. Calculate the prefix sum of v to get the number of elements that can be made equal to each index in v.
    //  4. Find the maximum value in v which represents the maximum beauty of the array after applying the operation.
    // 5. Return the maximum value in v.
    int maximumBeauty(vector<int> &nums, int k)
    {
        int x = *max_element(nums.begin(), nums.end()) + k;
        vector<int> v(x + 2);
        for (int i = 0; i < nums.size(); i++)
        {
            int x = max(0, nums[i] - k);
            v[x]++;
            v[nums[i] + k + 1]--;
        }
        for (int i = 1; i < v.size(); i++)
        {
            v[i] += v[i - 1];
        }
        int mx = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > mx)
            {
                mx = v[i];
            }
        }
        return mx;
    }
};
