// Link: https://leetcode.com/problems/maximum-good-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> minPrefix;
        long long prefix = 0;
        long long ans = LLONG_MIN;
        for (int x : nums) {
            if (minPrefix.count(x - k)) ans = max(ans, prefix + x - minPrefix[x - k]);
            if (minPrefix.count(x + k)) ans = max(ans, prefix + x - minPrefix[x + k]);
            if (!minPrefix.count(x) || minPrefix[x] > prefix) minPrefix[x] = prefix;
            prefix += x;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};
