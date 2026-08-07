// Link: https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(k)
// Approach: monotonic decreasing deque of indices; front is always the current window's max,
// pop from back while smaller than the incoming value, pop from front once it slides out of the window
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
