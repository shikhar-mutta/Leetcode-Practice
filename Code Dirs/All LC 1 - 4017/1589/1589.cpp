// Link: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        for (auto& r : requests) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }
        vector<long long> freq(n);
        long long running = 0;
        for (int i = 0; i < n; i++) {
            running += diff[i];
            freq[i] = running;
        }

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        const long long MOD = 1e9 + 7;
        long long total = 0;
        for (int i = 0; i < n; i++) total = (total + freq[i] * nums[i]) % MOD;
        return (int)total;
    }
};
