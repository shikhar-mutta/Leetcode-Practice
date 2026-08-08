// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);
        cnt[0] = 1;
        int sum = 0, res = 0;
        for (int x : nums) {
            sum = ((sum + x) % k + k) % k;
            res += cnt[sum];
            cnt[sum]++;
        }
        return res;
    }
};
