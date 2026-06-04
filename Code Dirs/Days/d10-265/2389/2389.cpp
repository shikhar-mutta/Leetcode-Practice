// Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: sort the array and find the prefix sum. TC: O(nlogn) + O(mlogn). SC: O(1)
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1]; // prefix sum
        for (int q : queries)
        { // upper_bound returns an iterator to the first element greater than value
            int idx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};
