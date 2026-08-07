// Link: https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(sum))  SC: O(1)
// Approach: binary search on the max-subarray-sum answer; greedily count
// how many subarrays are needed for a given cap, adjust bounds accordingly
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;
        for (int x : nums) { lo = max(lo, (long long)x); hi += x; }

        auto countParts = [&](long long cap) {
            int parts = 1;
            long long sum = 0;
            for (int x : nums) {
                if (sum + x > cap) { parts++; sum = x; }
                else sum += x;
            }
            return parts;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countParts(mid) > k) lo = mid + 1;
            else hi = mid;
        }
        return (int)lo;
    }
};
