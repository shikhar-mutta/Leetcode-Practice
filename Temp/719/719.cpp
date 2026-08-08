// Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + n log(max-min)) SC: O(1)
// Approach: sort nums; binary search on the distance value; count pairs with distance <= mid using a sliding window (two pointers), find smallest distance where count >= k.
class Solution {
    int countPairs(vector<int>& nums, int dist) {
        int count = 0, left = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (nums[right] - nums[left] > dist) left++;
            count += right - left;
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums.front();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countPairs(nums, mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
