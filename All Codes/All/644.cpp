// Link: https://leetcode.com/problems/maximum-average-subarray-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(1/eps)) SC: O(n)
// Approach: binary search on the answer average `mid`; feasible if some subarray of length >= k has average >= mid, checked by subtracting mid from every element and testing if some subarray of length >= k has non-negative sum (via prefix sums and tracking the minimum prefix seen k steps back).
class Solution {
    bool feasible(vector<int>& nums, int k, double mid) {
        double sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i] - mid;
        if (sum >= 0) return true;
        double prev = 0, minPrev = 0;
        for (int i = k; i < (int)nums.size(); i++) {
            sum += nums[i] - mid;
            prev += nums[i-k] - mid;
            minPrev = min(minPrev, prev);
            if (sum - minPrev >= 0) return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double lo = *min_element(nums.begin(), nums.end());
        double hi = *max_element(nums.begin(), nums.end());
        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2;
            if (feasible(nums, k, mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};
