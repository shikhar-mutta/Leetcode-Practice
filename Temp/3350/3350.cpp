// Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> incLen(n), fwdLen(n);
        incLen[0] = 1;
        for (int i = 1; i < n; i++) {
            incLen[i] = (nums[i] > nums[i-1]) ? incLen[i-1] + 1 : 1;
        }
        fwdLen[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            fwdLen[i] = (nums[i] < nums[i+1]) ? fwdLen[i+1] + 1 : 1;
        }

        int best = 0;
        for (int p = 1; p < n; p++) {
            best = max(best, min(incLen[p-1], fwdLen[p]));
        }
        return best;
    }
};
