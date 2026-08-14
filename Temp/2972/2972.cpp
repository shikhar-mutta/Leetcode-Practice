// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int preLen = 1;
        while (preLen < n && nums[preLen] > nums[preLen-1]) preLen++;
        if (preLen == n) return (long long)n * (n + 1) / 2;

        int suf0 = n - 1;
        while (suf0 > 0 && nums[suf0-1] < nums[suf0]) suf0--;

        long long total = 0;
        for (int i = 0; i <= preLen; i++) {
            int lowS = max(i + 1, suf0);
            int s0;
            if (i == 0) {
                s0 = lowS;
            } else {
                int lo = lowS, hi = n - 1, res = n;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (nums[mid] > nums[i-1]) { res = mid; hi = mid - 1; }
                    else lo = mid + 1;
                }
                s0 = res;
            }
            total += (n - s0 + 1);
        }
        return total;
    }
};
