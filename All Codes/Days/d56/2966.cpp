// Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) + O(n), SC: O(1)
    //  Approach:
    //   1. Count sort the array
    //   2. Iterate through the array in steps of 3 and check if the difference between the first and last element of the triplet is less than or equal to k
    //   3. If the difference is greater than k, return an empty array
    //   4. If the difference is less than or equal to k, add the triplet to the result array
    //   5. Reset the count sort array to 0 for the next test case
    //  Note: The count sort array is thread local
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        thread_local int csort[100001] = {0};
        for (const int x : nums)
        {
            ++csort[x];
        }
        for (int i = 0, j = 0; i <= 100001 && j < nums.size(); ++i)
        {
            std::fill(nums.begin() + j, nums.begin() + j + csort[i], i);
            j += csort[i];
        }
        // std::sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); j += 3)
        {
            if (nums[j + 2] - nums[j] > k)
            {
                for (const int x : nums)
                {
                    csort[x] = 0;
                }
                return {};
            }
        }
        std::vector<std::vector<int>> result(
            nums.size() / 3,
            std::vector<int>(3, 0));
        for (int i = 0, j = 0; j < nums.size(); ++i, j += 3)
        {
            result[i][0] = nums[j];
            result[i][1] = nums[j + 1];
            result[i][2] = nums[j + 2];
            csort[nums[j]] = 0;
            csort[nums[j + 1]] = 0;
            csort[nums[j + 2]] = 0;
        }
        return result;
    }
};
