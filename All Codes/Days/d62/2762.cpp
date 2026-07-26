// Link: https://leetcode.com/problems/continuous-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the two monotonic deques
// Approach: sliding window maintained via two monotonic deques (max-deque
// decreasing, min-deque increasing) so the window's current max/min are
// always at the fronts in O(1). Shrink from the left whenever max-min > 2;
// every valid window ending at `right` contributes (right-left+1) new
// subarrays (all of them, since any sub-window of a valid window is valid too).
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        deque<int> maxD; // stores indices, values in decreasing order
        deque<int> minD; // stores indices, values in increasing order

        long long ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Maintain max deque
            while (!maxD.empty() && nums[maxD.back()] < nums[right])
                maxD.pop_back();

            maxD.push_back(right);

            // Maintain min deque
            while (!minD.empty() && nums[minD.back()] > nums[right])
                minD.pop_back();

            minD.push_back(right);

            // Shrink window if invalid
            while (nums[maxD.front()] - nums[minD.front()] > 2) {

                if (maxD.front() == left)
                    maxD.pop_front();

                if (minD.front() == left)
                    minD.pop_front();

                left++;
            }

            // Count valid subarrays ending at right
            ans += (right - left + 1);
        }

        return ans;
    }
};
