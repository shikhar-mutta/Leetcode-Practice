// Link: https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> dq; // indices, values decreasing front→back
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front(); // drop out-of-window
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back(); // drop smaller values
            dq.push_back(i);   // add new value
            if (i >= k - 1)    // start adding to results after first window
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
