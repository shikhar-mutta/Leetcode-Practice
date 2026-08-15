// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                long long d = seen.size();
                ans += d * d;
            }
        }
        return (int)ans;
    }
};
