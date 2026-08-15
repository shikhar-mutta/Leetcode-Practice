// Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        auto countPairs = [&](int maxDiff) {
            int count = 0;
            int i = 0;
            while (i + 1 < n) {
                if (nums[i+1] - nums[i] <= maxDiff) {
                    count++;
                    i += 2;
                } else {
                    i++;
                }
            }
            return count;
        };

        int lo = 0, hi = (n > 0) ? nums[n-1] - nums[0] : 0;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countPairs(mid) >= p) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
