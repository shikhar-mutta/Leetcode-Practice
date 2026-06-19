// Link: https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n), SC: O(n)
    void backtrack(vector<int> &nums, int start, vector<int> &subset, vector<vector<int>> &res)
    {
        res.push_back(subset); // Add the current subset to the result
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1]) // Skip duplicates
                continue;
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, res); // Recur with the next index
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }
};
