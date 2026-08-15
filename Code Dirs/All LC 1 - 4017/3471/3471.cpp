// Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        if (k == 1) {
            int ans = -1;
            for (auto& [v, c] : freq) if (c == 1) ans = max(ans, v);
            return ans;
        }
        int ans = -1;
        if (freq[nums[0]] == 1) ans = max(ans, nums[0]);
        if (freq[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};
