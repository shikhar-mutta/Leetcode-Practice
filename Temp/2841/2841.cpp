// Link: https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            freq[nums[i]]++;
            if (i >= k) {
                sum -= nums[i - k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            }
            if (i >= k - 1 && (int)freq.size() >= m) ans = max(ans, sum);
        }
        return ans;
    }
};
