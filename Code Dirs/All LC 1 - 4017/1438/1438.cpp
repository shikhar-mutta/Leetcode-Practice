// Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDq, minDq;
        int left = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (!maxDq.empty() && nums[maxDq.back()] < nums[right]) maxDq.pop_back();
            maxDq.push_back(right);
            while (!minDq.empty() && nums[minDq.back()] > nums[right]) minDq.pop_back();
            minDq.push_back(right);

            while (nums[maxDq.front()] - nums[minDq.front()] > limit) {
                left++;
                if (maxDq.front() < left) maxDq.pop_front();
                if (minDq.front() < left) minDq.pop_front();
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
