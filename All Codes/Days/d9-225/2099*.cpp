// Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        // maxheap: (value, -index) for sorting by value desc, index asc
        // minheap: (index, value) for sorting by index asc
        priority_queue<pair<int, int>> maxheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            maxheap.push({nums[i], -i}); // -index: for equal values, smaller index wins
        }
        int cnt = 0;
        // Get top k elements from maxheap and push to minheap
        while (!maxheap.empty() && cnt < k)
        {
            int val = maxheap.top().first;
            int idx = -maxheap.top().second; // recover original index
            minheap.push({idx, val});
            maxheap.pop();
            cnt += 1;
        }

        // Extract values from minheap in index order
        vector<int> ans;

        //  minheap is sorted by index, so we get the values in the original order
        while (!minheap.empty())
        {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        return ans;
    }
};