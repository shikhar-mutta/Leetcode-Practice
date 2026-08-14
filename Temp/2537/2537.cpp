// Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        long long ans = 0, pairs = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;
            while (pairs >= k) {
                ans += n - right;
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }
        return ans;
    }
};
