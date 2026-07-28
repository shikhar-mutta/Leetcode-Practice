// Link: https://leetcode.com/problems/compare-sums-of-bitonic-parts/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: find the peak index, sum the ascending part (0..peak) and
// descending part (peak..n-1), compare.
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        for (int i = 1; i < n; i++) if (nums[i] > nums[peak]) peak = i;

        long long asc = 0, desc = 0;
        for (int i = 0; i <= peak; i++) asc += nums[i];
        for (int i = peak; i < n; i++) desc += nums[i];

        if (asc == desc) return -1;
        return asc > desc ? 0 : 1;
    }
};
