// Link: https://leetcode.com/problems/count-special-triplets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<long long,long long> suffixCount;
        for (int x : nums) suffixCount[x]++;

        unordered_map<long long,long long> prefixCount;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            long long target = (long long)nums[j] * 2;
            suffixCount[nums[j]]--;

            long long left = prefixCount.count(target) ? prefixCount[target] : 0;
            long long right = suffixCount.count(target) ? suffixCount[target] : 0;
            ans = (ans + (left * right) % MOD) % MOD;

            prefixCount[nums[j]]++;
        }

        return (int)ans;
    }
};
