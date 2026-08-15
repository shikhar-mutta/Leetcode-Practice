// Link: https://leetcode.com/problems/count-number-of-bad-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> cnt;
        for (int i = 0; i < n; i++) cnt[nums[i] - i]++;
        long long total = (long long)n * (n - 1) / 2;
        long long good = 0;
        for (auto& [k, c] : cnt) good += c * (c - 1) / 2;
        return total - good;
    }
};
