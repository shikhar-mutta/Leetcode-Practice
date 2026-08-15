// Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const long long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pow2(n, 1);
        for (int i = 1; i < n; i++) pow2[i] = pow2[i-1] * 2 % MOD;

        int left = 0, right = n - 1;
        long long count = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + pow2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }
        return (int)count;
    }
};
