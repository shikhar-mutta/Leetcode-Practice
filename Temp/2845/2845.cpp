// Link: https://leetcode.com/problems/count-of-interesting-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> cnt;
        cnt[0] = 1;
        int prefix = 0;
        long long ans = 0;
        for (int x : nums) {
            if (x % modulo == k) prefix = (prefix + 1) % modulo;
            int need = ((prefix - k) % modulo + modulo) % modulo;
            ans += cnt[need];
            cnt[prefix]++;
        }
        return ans;
    }
};
