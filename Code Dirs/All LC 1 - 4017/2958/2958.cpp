// Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, ans = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            freq[nums[r]]++;
            while (freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
