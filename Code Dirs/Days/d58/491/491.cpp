// Link: https://leetcode.com/problems/non-decreasing-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) where n is the length of the input array nums.
// SC: O(n) for the recursion stack and O(k) for storing the subsequences, where k is the number of valid subsequences found.
// Approach:
// 1. We can use backtracking to generate all possible subsequences of the input array nums.
// 2. We maintain a current subsequence curr and an index idx to track the position in the input array.
// 3. At each step, we have two choices: either include the current element nums[idx] in the subsequence or skip it.
// 4. If we include the current element, we check if it is greater than or equal to the last element in the current subsequence. If it is, we add it to curr and recursively call backtrack with the next index and the current element as the new last element.
// 5. If we skip the current element, we simply call backtrack with the next index and the same last element.
// 6. When we reach the end of the input array, we check if the current subsequence curr has at least two elements. If it does, we add it to the list of valid subsequences subs.
// 7. Finally, we return the list of valid subsequences subs.
class Solution
{
private:
    void backtrack(vector<int> &nums, int idx, int last, vector<int> &curr, vector<vector<int>> &subs)
    {
        if (idx == nums.size())
        {
            if (curr.size() >= 2)
            {
                subs.push_back(curr);
            }
            return;
        }

        if (nums[idx] >= last)
        {
            curr.push_back(nums[idx]);
            backtrack(nums, idx + 1, nums[idx], curr, subs);
            curr.pop_back();
        }

        if (nums[idx] != last)
        {
            backtrack(nums, idx + 1, last, curr, subs);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        vector<vector<int>> subs;
        vector<int> curr;
        backtrack(nums, 0, INT_MIN, curr, subs);
        return subs;
    }
};