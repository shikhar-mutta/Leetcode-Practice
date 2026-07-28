// Link: https://leetcode.com/problems/sliding-window-median/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log k)  SC: O(k)
// Approach: maintain the current window as a sorted multiset; each step
// erase the outgoing element and insert the incoming one (O(log k) via
// iterator lookup), then read the median from the iterator at position
// k/2 (using multiset::begin advanced, tracked incrementally).
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> ans;

        auto getMedian = [&]() -> double {
            if (k % 2 == 1) return (double)*mid;
            return ((double)*mid + (double)*prev(mid)) / 2.0;
        };

        ans.push_back(getMedian());
        for (int i = k; i < (int)nums.size(); i++) {
            window.insert(nums[i]);
            if (nums[i] < *mid) mid--;

            if (nums[i - k] <= *mid) mid++;
            window.erase(window.find(nums[i - k]));

            ans.push_back(getMedian());
        }
        return ans;
    }
};
