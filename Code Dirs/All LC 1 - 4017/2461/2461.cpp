// Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        long long sum = 0, best = 0;
        int distinct = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (++freq[nums[i]] == 1) distinct++;
            if (i >= k) {
                sum -= nums[i-k];
                if (--freq[nums[i-k]] == 0) distinct--;
            }
            if (i >= k - 1 && distinct == k) best = max(best, sum);
        }
        return best;
    }
};
