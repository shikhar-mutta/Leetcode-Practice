// Link: https://leetcode.com/problems/find-the-distinct-difference-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        // map to store frequency of elements in left and right subarrays
        unordered_map<int, int> leftFreq, rightFreq;
        // initialize rightFreq with frequency of all elements in nums
        for (int x : nums)
            rightFreq[x]++;
        // iterate through nums and update leftFreq and rightFreq
        for (int i = 0; i < n; i++)
        {
            if (--rightFreq[nums[i]] == 0)
                rightFreq.erase(nums[i]);
            leftFreq[nums[i]]++;
            // calculate the distinct difference for the current index
            ans[i] = leftFreq.size() - rightFreq.size();
        }
        return ans;
    }
};
