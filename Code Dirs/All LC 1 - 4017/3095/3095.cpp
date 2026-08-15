// Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(32, 0);
        int l = 0, ans = INT_MAX;
        auto orVal = [&]() {
            int v = 0;
            for (int b = 0; b < 32; b++) if (bitCount[b] > 0) v |= (1 << b);
            return v;
        };
        for (int r = 0; r < n; r++) {
            for (int b = 0; b < 32; b++) if (nums[r] & (1 << b)) bitCount[b]++;
            while (l <= r && orVal() >= k) {
                ans = min(ans, r - l + 1);
                for (int b = 0; b < 32; b++) if (nums[l] & (1 << b)) bitCount[b]--;
                l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
