// Link: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: countAtMost(bound) counts subarrays whose max <= bound via a run-length trick; answer is countAtMost(right) - countAtMost(left-1).
class Solution {
    long long countAtMost(vector<int>& nums, int bound) {
        long long count = 0, run = 0;
        for (int x : nums) {
            run = (x <= bound) ? run+1 : 0;
            count += run;
        }
        return count;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return (int)(countAtMost(nums, right) - countAtMost(nums, left-1));
    }
};
