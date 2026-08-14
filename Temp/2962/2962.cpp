// Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int l = 0, cnt = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] == maxVal) cnt++;
            while (cnt >= k) {
                if (nums[l] == maxVal) cnt--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};
