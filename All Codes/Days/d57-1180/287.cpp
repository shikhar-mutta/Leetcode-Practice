// Link: https://leetcode.com/problems/find-the-duplicate-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    // Approach:
    //  1. Create a vector of size n+1 to keep track of the count of each number in the input vector.
    //  2. Iterate through the input vector and increment the count of each number in the count vector.
    //  3. Iterate through the count vector and return the index of the first number that has a count greater than 1, which is the duplicate number.
    //  4. If no duplicate number is found, return -1.
    int findDuplicate(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size();
        vector<int> check(nums.size(), 0);
        for (int i = 0; i < right; i++)
        {
            check[nums[i]]++;
        }
        int a = 0;
        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] > 1)
            {
                a = i;
            }
        }

        return a;
    }
};