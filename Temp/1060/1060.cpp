// Link: https://leetcode.com/problems/missing-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int missingCount = [&](int i) { return nums[i] - nums[0] - i; }(n - 1);
        if (k > missingCount) return nums[n-1] + (k - missingCount);

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int missing = nums[mid] - nums[0] - mid;
            if (missing < k) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo - 1] + (k - (nums[lo-1] - nums[0] - (lo-1)));
    }
};
