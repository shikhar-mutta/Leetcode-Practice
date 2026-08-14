// Link: https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int last1, int last2) {
        int n = nums1.size();
        int dp0 = 0, dp1 = 1;
        bool valid0 = (n < 2) || (nums1[0] <= last1 && nums2[0] <= last2);
        bool valid1 = (n < 2) || (nums2[0] <= last1 && nums1[0] <= last2);
        if (!valid0) dp0 = INT_MAX / 2;
        if (!valid1) dp1 = INT_MAX / 2;
        for (int i = 1; i < n - 1; i++) {
            int base = min(dp0, dp1);
            int ndp0 = (nums1[i] <= last1 && nums2[i] <= last2) ? base : INT_MAX / 2;
            int ndp1 = (nums2[i] <= last1 && nums1[i] <= last2) ? base + 1 : INT_MAX / 2;
            dp0 = ndp0; dp1 = ndp1;
        }
        if (n < 2) return 0;
        return min(dp0, dp1);
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int keep = solve(nums1, nums2, nums1[n-1], nums2[n-1]);
        int swapLast = solve(nums1, nums2, nums2[n-1], nums1[n-1]);
        int ans = min(keep, swapLast + 1);
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};
